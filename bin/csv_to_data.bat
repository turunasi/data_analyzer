@echo off
setlocal EnableDelayedExpansion
cd /d %~dp0

set DEFAULT_DATA_DIRECTORY=DAT
set DEFAULT_SORTED_DATA_DIRECTORY=DAT2
set DEFAULT_INITIAL_DIRECTORY=initial
set DEFAULT_RESULT_DIRECTORY=result
set DEFAULT_BATCH_DIRECTORY=bat

echo "CSV�t�@�C����Excell�ŊJ�����܂܂ɂ���Ɠǂݍ��܂�܂���B����!!"
set /p csv_file_path="CSV�t�@�C���̃p�X����͂��Ă������� : "
if not exist %csv_file_path% (
    echo CSV�f�[�^�̎擾�Ɏ��s���܂����B
    pause
    exit
)
echo CSV�f�[�^�𔭌����܂����B
echo CSV�f�[�^��ǂݍ��݂܂��B
rem CSV�t�@�C���̃f�[�^��񎟌��z��Ɋi�[
set /a total_row_num=0
for /f "skip=1 delims=, tokens=1-7" %%a in (%csv_file_path%) do (
    rem N[Hz]����ɂȂ����Ƃ����CSV�̏I�[�Ƃ���
    if "%%g" == "" goto :exit_csv
    set CSV_DATA[!total_row_num!][0]=%%a
    set CSV_DATA[!total_row_num!][1]=%%b
    set CSV_DATA[!total_row_num!][2]=%%c
    set CSV_DATA[!total_row_num!][3]=%%d
    set CSV_DATA[!total_row_num!][4]=%%e
    set CSV_DATA[!total_row_num!][5]=%%f
    set CSV_DATA[!total_row_num!][6]=%%g
    set /a total_row_num+=1
)
:exit_csv
set /a total_row_num-=1

set /p home_directory_path="�f�[�^���Z�߂��Ă���f�B���N�g���̃p�X����͂��Ă������� ex) 21Axial/21data : "
if not exist %home_directory_path% (
    echo "�f�B���N�g���̎擾�Ɏ��s���܂���...\n"
    pause
    exit
)

set /p date_name="�f�[�^�擾������͂��Ă������� ex) 210915 : "

:loop_initial
    set /p make_initial="�C�j�V�����t�@�C�����쐬����ꍇ1���A�쐬���Ȃ����0���w�肵�Ă������� : "
    if not %make_initial% == 1 (
        if not %make_initial% == 0 (
            echo "�C�j�V�����t�@�C�����쐬����ꍇ1���A�쐬���Ȃ����0���w�肵�Ă��������B"
        ) else (
            goto :exit_initial
        )
    ) else (
        goto :exit_initial 
    )
goto :loop_initial
:exit_initial

:loop_position
    set /p position="�v�������n�̐ݒ肪�f�o�ǂȂ�1���A���k�@�Ȃ�0���w�肵�Ă������� : "
    if not %position% == 1 (
        if not %position% == 0 (
            echo "�v�������n�̐ݒ肪�s���ł��B�f�o�ǂȂ�1���A���k�@�Ȃ�0���w�肵�Ă��������B
        ) else (
            goto :exit_position
        )
    ) else (
        goto :exit_position
    )
goto :loop_position
:exit_position

:loop_initial_sp
    set /p position_sp="�È��𑪒肵���ꏊ���C�����b�g�Ȃ�2���A���k�@�����Ȃ�1���A���肵�Ȃ����0���w�肵�Ă������� : "
    if not %position_sp% == 2 (
        if not %position_sp% == 1 (
            if not %position_sp% == 0 (
                echo "�È��𑪒肵���ꏊ�̎w�肪�s���ł��B�C�����b�g�Ȃ�2���A���k�@�����Ȃ�0���A���肵�Ȃ����1���w�肵�Ă��������B"
            ) else (
                goto :exit_position_sp
            )
        ) else (
            goto :exit_position_sp
        )
    ) else (
        goto :exit_position_sp
    )
goto :loop_initial_sp
:exit_position_sp

set input_directory_path=%home_directory_path%%DEFAULT_DATA_DIRECTORY%\%date_name%
mkdir %input_directory_path%
set output_directory_path=%home_directory_path%%DEFAULT_SORTED_DATA_DIRECTORY%\%date_name%
mkdir %output_directory_path%

goto :skip

rem for /l %%i in (0,1,%total_row_num%) do (
rem     call echo %%CSV_DATA[%%i][0]%%
rem     call echo %%CSV_DATA[%%i][1]%%
rem     call echo %%CSV_DATA[%%i][2]%%
rem     call echo %%CSV_DATA[%%i][3]%%
rem     call echo %%CSV_DATA[%%i][4]%%
rem     call echo %%CSV_DATA[%%i][5]%%
rem     call echo %%CSV_DATA[%%i][6]%%
rem )

rem �f�[�^�𕪊�
for /l %%i in (0,1,%total_row_num%) do (
    set fn=!!CSV_DATA[%%i][1]!!
    set is_skip=!!CSV_DATA[%%i][2]!!
    if !!CSV_DATA[%%i][3]!! == Y (
        set /a is_initial=1
    ) else (
        set /a is_initial=0
    )
    rem Skip����s�ȊO���쐬
    if not !is_skip! == Y (
        sort.exe !fn! !is_initial! %input_directory_path% %output_directory_path% 0 0
        rem if %ERRORLEVEL% == 0 (
        rem     echo %fn%�̕����Ɏ��s���܂����B
        rem     exit
        rem )
    )
)

:skip
rem for %%i in (%output_directory_path%/*.DAT) do (
rem     for /d %%j in (%output_directory_path%/) do (copy %output_directory_path%/%%i %%j)
rem )
for /d %%i in (%output_directory_path%\*) do (
    copy %output_directory_path%\*.DAT %%i
) 

set initial_directory_path=%home_directory_path%%DEFAULT_INITIAL_DIRECTORY%\%date_name%
mkdir %initial_directory_path%
set result_directory_path=%home_directory_path%%DEFAULT_RESULT_DIRECTORY%\%date_name%
mkdir %result_directory_path%
set batch_directory_path=%home_directory_path%%DEFAULT_BATCH_DIRECTORY%\%date_name%
mkdir %batch_directory_path%

rem �o�b�`���쐬
set /a record_cnt=0
set /a init_cnt=0
rem ���������ǂ��� �����J�n���̃C�j�V�����t�@�C���𖳎����邽�߂ɐݒ�
set /a under_experiment=0
for /l %%i in (0,1,%total_row_num%) do (
    
    rem B�s��0���ǂ����Ń��R�[�h���Ă��邩�ǂ����𔻒�
    if !!CSV_DATA[%%i][1]!! == 0 (
        set /a is_record=0
    ) else (
        set /a is_record=1
    )

    rem C�s��Y���ǂ����ŃX�L�b�v���邩�ǂ����𔻒�
    if !!CSV_DATA[%%i][2]!! == Y (
        set /a is_skip=1
    ) else (
        set /a is_skip=0
    )
    
    rem D�s��Y���ǂ����ŃC�j�V�����t�@�C�����ǂ����𔻒�
    if !!CSV_DATA[%%i][3]!! == Y (
        set /a is_initial=1
    ) else (
        set /a is_initial=0
    )

    if !is_initial! equ 1 (
        if !is_record! equ 1 (
            rem �����J�n���̃C�j�V�����Ȃ̂Ńo�b�`�͍쐬���Ȃ�
            if not !under_experiment! equ 0 (
                rem ���R�[�h�������Ȃ�o�b�`�͍쐬���Ȃ�
                if not !record_cnt! equ 0 (
                    for /l %%j in (0,1,!init_cnt!) do (
                        set fn=!!CSV_DATA[%%i][1]!!
                        if %%j equ !init_cnt! (
                            set after_P=!!CSV_DATA[%%i][4]!!
                            set after_T=!!CSV_DATA[%%i][5]!!
                        ) else (
                            set /a after_init_cnt=%%j+1
                            set after_P=!!before_Ps[%after_init_cnt%]!!
                            set after_T=!!before_Ts[%after_init_cnt%]!!
                        )
                        for /l %%k in (0,1,!record_cnt!-1) do (
                            set record_id=!!RECORD_IDS[%%j][%%k]!!
                            set after_init_record_id=!!CSV_DATA[%%i][1]!!
                            set before_P=!!before_Ps[%%j]!!
                            set before_T=!!before_Ts[%%j]!!
                            set Nrev=!!Nrevs[%%j]!!
                            start make_bat.exe !record_id! !before_init_record_id! !after_init_record_id! 1 100 %input_directory_path% %result_directory_path% %batch_directory_path% %initial_directory_path% !before_P! !after_P! !before_T! !after_T! !Nrev! %make_initial% %position% %position_sp%
                            rem make_bat.exe 2 1 23 1 100 ..\DAT\210701 ..\result\210701 ..\bat\210701 ..\initial\210701 760.0 761.0 20.0 21.0 200.0 1 0 1
                            rem if %ERRORLEVEL% equ 1 (
                            rem     echo "!!RECORD_IDS[%%j][%%k]!!�̃o�b�`�쐬�Ɏ��s���܂����AE
                            rem     pause
                            rem     exit
                            rem )
                        )
                    )
                    set /a init_cnt=0
                    set /a record_cnt=0
                )
            ) else (
                rem �����J�n���̃C�j�V��������ꂽ�̂Ŏ����J�n
                set /a under_experiment=1
            )
            rem �J�n�C�j�V������ۑ�
            set before_init_record_id=!!CSV_DATA[%%i][1]!!
        ) else (
            rem �C�j�V�����J�E���g���C���N�������g
            set /a init_cnt+=1
        )
        rem �C�j�V�����擾���_�̈��͂Ɖ��x�Ɖ�]�����擾
        set before_Ps[!init_cnt!]=!!CSV_DATA[%%i][4]!!
        set before_Ts[!init_cnt!]=!!CSV_DATA[%%i][5]!!
        set Nrevs[!init_cnt!]=!!CSV_DATA[%%i][6]!!
    ) else (
        rem �X�L�b�v����Ȃ�o�b�`���쐬���Ȃ�
        if not !is_skip! equ 1 (
            rem ���R�[�h����Ȃ�RECORD_IDS�ɕۑ�
            if !is_record! equ 1 (
                set RECORD_IDS[!init_cnt!][!record_cnt!]=!!CSV_DATA[%%i][1]!!
                set /a record_cnt+=1
            )
        )
    )
)

rem �S�o�b�`��񓯊��Ŏ��s
for %%i in (%batch_directory_path%\*.bat) do start %%i
endlocal
exit
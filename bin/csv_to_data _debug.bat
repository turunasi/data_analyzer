@echo on
chcp 65001
setlocal EnableDelayedExpansion
cd /d %~dp0

set DEFAULT_DATA_DIRECTORY=DAT
set DEFAULT_SORTED_DATA_DIRECTORY=DAT2
set DEFAULT_INITIAL_DIRECTORY=initial
set DEFAULT_RESULT_DIRECTORY=result
set DEFAULT_BATCH_DIRECTORY=bat

echo "CSVファイルをExcellで開いたままにすると読み込まれません。うんち!!"
set /p csv_file_path="CSVファイルのパスを�E力してください : "
if not exist %csv_file_path% (
    echo CSVチE�Eタの取得に失敗しました、E
    pause
    exit
)
echo CSVチE�Eタを発見しました、E
echo CSVチE�Eタを読み込みます、E
rem CSVファイルのチE�Eタを二次允E�E列に格紁E
set /a total_row_num=0
for /f "skip=1 delims=, tokens=1-7" %%a in (%csv_file_path%) do (
    rem N[Hz]が空になったところをCSVの終端とす�
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

set /p home_directory_path="チE�Eタが纏められてぁE��チE��レクトリのパスを�E力してください ex) 21Axial/21data : "
if not exist %home_directory_path% (
    echo "チE��レクトリの取得に失敗しました...\n"
    pause
    exit
)

set /p date_name="チE�Eタ取得日を�E力してください ex) 210915 : "

:loop_initial
    set /p make_initial="イニシャルファイルを作�Eする場吁Eを、作�Eしなければ0を指定してください : "
    if not %make_initial% == 1 (
        if not %make_initial% == 0 (
            echo "イニシャルファイルを作�Eする場吁Eを、作�Eしなければ0を指定してください、E
        ) else (
            goto :exit_initial
        )
    ) else (
        goto :exit_initial 
    )
goto :loop_initial
:exit_initial

:loop_position
    set /p position="計測した系の設定が吐�E管なめEを、圧縮機なめEを指定してください : "
    if not %position% == 1 (
        if not %position% == 0 (
            echo "計測した系の設定が不正です。吐出管なめEを、圧縮機なめEを指定してください、E
        ) else (
            goto :exit_position
        )
    ) else (
        goto :exit_position
    )
goto :loop_position
:exit_position

:loop_initial_sp
    set /p position_sp="静圧を測定した場所がインレチE��なめEを、圧縮機�E部なめEを、測定しなければ0を指定してください : "
    if not %position_sp% == 2 (
        if not %position_sp% == 1 (
            if not %position_sp% == 0 (
                echo "静圧を測定した場所の持E��が不正です。インレチE��なめEを、圧縮機�E部なめEを、測定しなければ0を指定してください、E
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

set input_directory_path=%home_directory_path%%DEFAULT_DATA_DIRECTORY%/%date_name%
set output_directory_path=%home_directory_path%%DEFAULT_SORTED_DATA_DIRECTORY%/%date_name%
pause

rem for /l %%i in (0,1,%total_row_num%) do (
rem     call echo %%CSV_DATA[%%i][0]%%
rem     call echo %%CSV_DATA[%%i][1]%%
rem     call echo %%CSV_DATA[%%i][2]%%
rem     call echo %%CSV_DATA[%%i][3]%%
rem     call echo %%CSV_DATA[%%i][4]%%
rem     call echo %%CSV_DATA[%%i][5]%%
rem     call echo %%CSV_DATA[%%i][6]%%
rem )

rem チE�Eタを�E割
pause
for /l %%i in (1,1,%total_row_num%) do (
    set fn=!!CSV_DATA[%%i][1]!!
    set is_skip=!!CSV_DATA[%%i][2]!!
    rem if !!CSV_DATA[%%i][3]!! == Y (
    rem     set /a is_initial=1
    rem ) else (
    rem     set /a is_initial=0
    rem )
    pause
    rem Skipする行以外を作�E
    rem if not !is_skip! == Y (
    rem     start sort.exe !fn! !is_initial! %input_directory_path% %output_directory_path% 0 0
    rem     if %ERRORLEVEL% == 0 (
    rem         echo %fn%の刁E��に失敗しました、E
    rem         pause
    rem         exit
    rem     )
    rem )
)

pause
cd %output_directory_path%
for %%i in (*.DAT) do (
    for /d %%j in (*) copy %%i %%j/
) 
cd /d %~dp0

exit

set initial_directory_path=%home_directory_path%/%DEFAULT_INITIAL_DIRECTORY%/%date_name%
set result_directory_path=%home_directory_path%/%DEFAULT_RESULT_DIRECTORY%/%date_name%
set batch_directory_path=%home_directory_path%/%DEFAULT_BATCH_DIRECTORY%/%date_name%

rem バッチを作�E
set /a record_cnt=0
set /a init_cnt=0
for /l %%i in (0,1,%total_row_num%) do (
    
    rem B行が空白かどぁE�E��E�でレコードしてぁE�E��E�かどぁE�E��E�を判宁E
    if "%CSV_DATA[%%i][1]%" == "" (
        set /a is_record=0
    ) else (
        set /a is_record=1
    )

    rem C行がYかどぁE�E��E�でスキチE�E�EするかどぁE�E��E�を判宁E
    if "%CSV_DATA[%%i][2]%" == "" (
        set /a is_record=0
    ) else (
        set /a is_record=1
    )
    
    rem D行がYかどぁE�E��E�でイニシャルファイルかどぁE�E��E�を判宁E
    if %CSV_DATA[%%i][3]% == Y (
        set /a is_skip=1
    ) else (
        set /a is_skip=0
    )

    if %is_initial% equ 1 (
        if not %init_cnt% equ 0 (
            if not %record_cnt% equ 0 (
                for /l %%j in (0,1,%init_cnt%) do (
                    for /l %%k in (0,1,%record_cnt%) do (
                        start make_bat.exe %RECORD_IDS[%%j][%%k]% %before_init_record_id% %CSV_DATA[%%i][1]% 1 100 %input_directory_path% %result_directory_path% %batch_directory_path% %initial_directory_path% %before_Ps[%%j]% %CSV_DATA[%%i][4]% %before_T[%%j]% %CSV_DATA[%%i][5]% %Nrevs[%%j]% %make_initial%  %position%  %position_sp%
                        if %ERRORLEVEL% equ 1 (
                            echo "%RECORD_IDS[%%j][%%k]%のバッチ作�Eに失敗しました、E
                            pause
                            exit
                        )
                    )
                )
                set /a init_cnt=0
                set /a record_cnt=0
            )
        )
        if %is_record% equ 1 (
            set before_init_record_id=%%b
        ) else (
            set /a init_cnt+=1
        )
        set before_Ps[%init_cnt%]=%%e
        set before_Ts[%init_cnt%]=%%f
        set Nrevs[%init_cnt%]=%%g
    ) else (
        if not %is_skip% equ 1 (
            if %is_record% equ 1 (
                set RECORD_IDS[%init_cnt%][%record_cnt%]=%%b
                set /a record_cnt+=1
            )
        )
    )
)

rem バッチを作�EしたチE�E��E�レクトリに移勁E
cd %batch_directory_path%
rem 全バッチを非同期で実衁E
for %%i in (*.bat) do start %%i

endlocal
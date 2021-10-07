@echo on
chcp 65001
setlocal EnableDelayedExpansion
cd /d %~dp0

set DEFAULT_DATA_DIRECTORY=DAT
set DEFAULT_SORTED_DATA_DIRECTORY=DAT2
set DEFAULT_INITIAL_DIRECTORY=initial
set DEFAULT_RESULT_DIRECTORY=result
set DEFAULT_BATCH_DIRECTORY=bat

echo "CSV繝輔ぃ繧､繝ｫ繧脱xcell縺ｧ髢九＞縺溘∪縺ｾ縺ｫ縺吶ｋ縺ｨ隱ｭ縺ｿ霎ｼ縺ｾ繧後∪縺帙ｓ縲ゅ≧繧薙■!!"
set /p csv_file_path="CSV繝輔ぃ繧､繝ｫ縺ｮ繝代せ繧貞・蜉帙＠縺ｦ縺上□縺輔＞ : "
if not exist %csv_file_path% (
    echo CSV繝・・繧ｿ縺ｮ蜿門ｾ励↓螟ｱ謨励＠縺ｾ縺励◆縲・
    pause
    exit
)
echo CSV繝・・繧ｿ繧堤匱隕九＠縺ｾ縺励◆縲・
echo CSV繝・・繧ｿ繧定ｪｭ縺ｿ霎ｼ縺ｿ縺ｾ縺吶・
rem CSV繝輔ぃ繧､繝ｫ縺ｮ繝・・繧ｿ繧剃ｺ梧ｬ｡蜈・・蛻励↓譬ｼ邏・
set /a total_row_num=0
for /f "skip=1 delims=, tokens=1-7" %%a in (%csv_file_path%) do (
    rem N[Hz]縺檎ｩｺ縺ｫ縺ｪ縺｣縺溘→縺薙ｍ繧辰SV縺ｮ邨らｫｯ縺ｨ縺吶
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

set /p home_directory_path="繝・・繧ｿ縺檎ｺ上ａ繧峨ｌ縺ｦ縺・ｋ繝・ぅ繝ｬ繧ｯ繝医Μ縺ｮ繝代せ繧貞・蜉帙＠縺ｦ縺上□縺輔＞ ex) 21Axial/21data : "
if not exist %home_directory_path% (
    echo "繝・ぅ繝ｬ繧ｯ繝医Μ縺ｮ蜿門ｾ励↓螟ｱ謨励＠縺ｾ縺励◆...\n"
    pause
    exit
)

set /p date_name="繝・・繧ｿ蜿門ｾ玲律繧貞・蜉帙＠縺ｦ縺上□縺輔＞ ex) 210915 : "

:loop_initial
    set /p make_initial="繧､繝九す繝｣繝ｫ繝輔ぃ繧､繝ｫ繧剃ｽ懈・縺吶ｋ蝣ｴ蜷・繧偵∽ｽ懈・縺励↑縺代ｌ縺ｰ0繧呈欠螳壹＠縺ｦ縺上□縺輔＞ : "
    if not %make_initial% == 1 (
        if not %make_initial% == 0 (
            echo "繧､繝九す繝｣繝ｫ繝輔ぃ繧､繝ｫ繧剃ｽ懈・縺吶ｋ蝣ｴ蜷・繧偵∽ｽ懈・縺励↑縺代ｌ縺ｰ0繧呈欠螳壹＠縺ｦ縺上□縺輔＞縲・
        ) else (
            goto :exit_initial
        )
    ) else (
        goto :exit_initial 
    )
goto :loop_initial
:exit_initial

:loop_position
    set /p position="險域ｸｬ縺励◆邉ｻ縺ｮ險ｭ螳壹′蜷仙・邂｡縺ｪ繧・繧偵∝悸邵ｮ讖溘↑繧・繧呈欠螳壹＠縺ｦ縺上□縺輔＞ : "
    if not %position% == 1 (
        if not %position% == 0 (
            echo "險域ｸｬ縺励◆邉ｻ縺ｮ險ｭ螳壹′荳肴ｭ｣縺ｧ縺吶ょ瑞蜃ｺ邂｡縺ｪ繧・繧偵∝悸邵ｮ讖溘↑繧・繧呈欠螳壹＠縺ｦ縺上□縺輔＞縲・
        ) else (
            goto :exit_position
        )
    ) else (
        goto :exit_position
    )
goto :loop_position
:exit_position

:loop_initial_sp
    set /p position_sp="髱吝悸繧呈ｸｬ螳壹＠縺溷ｴ謇縺後う繝ｳ繝ｬ繝・ヨ縺ｪ繧・繧偵∝悸邵ｮ讖溷・驛ｨ縺ｪ繧・繧偵∵ｸｬ螳壹＠縺ｪ縺代ｌ縺ｰ0繧呈欠螳壹＠縺ｦ縺上□縺輔＞ : "
    if not %position_sp% == 2 (
        if not %position_sp% == 1 (
            if not %position_sp% == 0 (
                echo "髱吝悸繧呈ｸｬ螳壹＠縺溷ｴ謇縺ｮ謖・ｮ壹′荳肴ｭ｣縺ｧ縺吶ゅう繝ｳ繝ｬ繝・ヨ縺ｪ繧・繧偵∝悸邵ｮ讖溷・驛ｨ縺ｪ繧・繧偵∵ｸｬ螳壹＠縺ｪ縺代ｌ縺ｰ0繧呈欠螳壹＠縺ｦ縺上□縺輔＞縲・
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

rem 繝・・繧ｿ繧貞・蜑ｲ
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
    rem Skip縺吶ｋ陦御ｻ･螟悶ｒ菴懈・
    rem if not !is_skip! == Y (
    rem     start sort.exe !fn! !is_initial! %input_directory_path% %output_directory_path% 0 0
    rem     if %ERRORLEVEL% == 0 (
    rem         echo %fn%縺ｮ蛻・牡縺ｫ螟ｱ謨励＠縺ｾ縺励◆縲・
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

rem 繝舌ャ繝√ｒ菴懶ｿｽE
set /a record_cnt=0
set /a init_cnt=0
for /l %%i in (0,1,%total_row_num%) do (
    
    rem B陦後′遨ｺ逋ｽ縺九←縺・・ｽ・ｽ縺ｧ繝ｬ繧ｳ繝ｼ繝峨＠縺ｦ縺・・ｽ・ｽ縺九←縺・・ｽ・ｽ繧貞愛螳・
    if "%CSV_DATA[%%i][1]%" == "" (
        set /a is_record=0
    ) else (
        set /a is_record=1
    )

    rem C陦後′Y縺九←縺・・ｽ・ｽ縺ｧ繧ｹ繧ｭ繝・・ｽE縺吶ｋ縺九←縺・・ｽ・ｽ繧貞愛螳・
    if "%CSV_DATA[%%i][2]%" == "" (
        set /a is_record=0
    ) else (
        set /a is_record=1
    )
    
    rem D陦後′Y縺九←縺・・ｽ・ｽ縺ｧ繧､繝九す繝｣繝ｫ繝輔ぃ繧､繝ｫ縺九←縺・・ｽ・ｽ繧貞愛螳・
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
                            echo "%RECORD_IDS[%%j][%%k]%縺ｮ繝舌ャ繝∽ｽ懶ｿｽE縺ｫ螟ｱ謨励＠縺ｾ縺励◆縲・
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

rem 繝舌ャ繝√ｒ菴懶ｿｽE縺励◆繝・・ｽ・ｽ繝ｬ繧ｯ繝医Μ縺ｫ遘ｻ蜍・
cd %batch_directory_path%
rem 蜈ｨ繝舌ャ繝√ｒ髱槫酔譛溘〒螳溯｡・
for %%i in (*.bat) do start %%i

endlocal
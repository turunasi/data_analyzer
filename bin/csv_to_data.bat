@echo off
setlocal EnableDelayedExpansion
cd /d %~dp0

set DEFAULT_DATA_DIRECTORY=DAT
set DEFAULT_SORTED_DATA_DIRECTORY=DAT2
set DEFAULT_INITIAL_DIRECTORY=initial
set DEFAULT_RESULT_DIRECTORY=result
set DEFAULT_BATCH_DIRECTORY=bat

echo "CSVファイルをExcellで開いたままにすると読み込まれません。うんち!!"
set /p csv_file_path="CSVファイルのパスを入力してください : "
if not exist %csv_file_path% (
    echo CSVデータの取得に失敗しました。
    pause
    exit
)
echo CSVデータを発見しました。
echo CSVデータを読み込みます。
rem CSVファイルのデータを二次元配列に格納
set /a total_row_num=0
for /f "skip=1 delims=, tokens=1-7" %%a in (%csv_file_path%) do (
    rem N[Hz]が空になったところをCSVの終端とする
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

set /p home_directory_path="データが纏められているディレクトリのパスを入力してください ex) 21Axial/21data : "
if not exist %home_directory_path% (
    echo "ディレクトリの取得に失敗しました...\n"
    pause
    exit
)

set /p date_name="データ取得日を入力してください ex) 210915 : "

:loop_initial
    set /p make_initial="イニシャルファイルを作成する場合1を、作成しなければ0を指定してください : "
    if not %make_initial% == 1 (
        if not %make_initial% == 0 (
            echo "イニシャルファイルを作成する場合1を、作成しなければ0を指定してください。"
        ) else (
            goto :exit_initial
        )
    ) else (
        goto :exit_initial 
    )
goto :loop_initial
:exit_initial

:loop_position
    set /p position="計測した系の設定が吐出管なら1を、圧縮機なら0を指定してください : "
    if not %position% == 1 (
        if not %position% == 0 (
            echo "計測した系の設定が不正です。吐出管なら1を、圧縮機なら0を指定してください。
        ) else (
            goto :exit_position
        )
    ) else (
        goto :exit_position
    )
goto :loop_position
:exit_position

:loop_initial_sp
    set /p position_sp="静圧を測定した場所がインレットなら2を、圧縮機内部なら1を、測定しなければ0を指定してください : "
    if not %position_sp% == 2 (
        if not %position_sp% == 1 (
            if not %position_sp% == 0 (
                echo "静圧を測定した場所の指定が不正です。インレットなら2を、圧縮機内部なら0を、測定しなければ1を指定してください。"
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

rem データを分割
for /l %%i in (0,1,%total_row_num%) do (
    set fn=!!CSV_DATA[%%i][1]!!
    set is_skip=!!CSV_DATA[%%i][2]!!
    if !!CSV_DATA[%%i][3]!! == Y (
        set /a is_initial=1
    ) else (
        set /a is_initial=0
    )
    rem Skipする行以外を作成
    if not !is_skip! == Y (
        sort.exe !fn! !is_initial! %input_directory_path% %output_directory_path% 0 0
        rem if %ERRORLEVEL% == 0 (
        rem     echo %fn%の分割に失敗しました。
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

rem バッチを作成
set /a record_cnt=0
set /a init_cnt=0
rem 実験中かどうか 実験開始時のイニシャルファイルを無視するために設定
set /a under_experiment=0
for /l %%i in (0,1,%total_row_num%) do (
    
    rem B行が0かどうかでレコードしているかどうかを判定
    if !!CSV_DATA[%%i][1]!! == 0 (
        set /a is_record=0
    ) else (
        set /a is_record=1
    )

    rem C行がYかどうかでスキップするかどうかを判定
    if !!CSV_DATA[%%i][2]!! == Y (
        set /a is_skip=1
    ) else (
        set /a is_skip=0
    )
    
    rem D行がYかどうかでイニシャルファイルかどうかを判定
    if !!CSV_DATA[%%i][3]!! == Y (
        set /a is_initial=1
    ) else (
        set /a is_initial=0
    )

    if !is_initial! equ 1 (
        if !is_record! equ 1 (
            rem 実験開始時のイニシャルなのでバッチは作成しない
            if not !under_experiment! equ 0 (
                rem レコードが無いならバッチは作成しない
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
                            rem     echo "!!RECORD_IDS[%%j][%%k]!!のバッチ作成に失敗しました、E
                            rem     pause
                            rem     exit
                            rem )
                        )
                    )
                    set /a init_cnt=0
                    set /a record_cnt=0
                )
            ) else (
                rem 実験開始時のイニシャルが取れたので実験開始
                set /a under_experiment=1
            )
            rem 開始イニシャルを保存
            set before_init_record_id=!!CSV_DATA[%%i][1]!!
        ) else (
            rem イニシャルカウントをインクリメント
            set /a init_cnt+=1
        )
        rem イニシャル取得時点の圧力と温度と回転数を取得
        set before_Ps[!init_cnt!]=!!CSV_DATA[%%i][4]!!
        set before_Ts[!init_cnt!]=!!CSV_DATA[%%i][5]!!
        set Nrevs[!init_cnt!]=!!CSV_DATA[%%i][6]!!
    ) else (
        rem スキップするならバッチを作成しない
        if not !is_skip! equ 1 (
            rem レコードするならRECORD_IDSに保存
            if !is_record! equ 1 (
                set RECORD_IDS[!init_cnt!][!record_cnt!]=!!CSV_DATA[%%i][1]!!
                set /a record_cnt+=1
            )
        )
    )
)

rem 全バッチを非同期で実行
for %%i in (%batch_directory_path%\*.bat) do start %%i
endlocal
exit
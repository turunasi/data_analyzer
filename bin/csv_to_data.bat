@echo off
cd /d %~dp0
setlocal enabledelayedexpansion

set DEFAULT_DATA_DIRECTORY=DAT
set DEFAULT_SORTED_DATA_DIRECTORY=DAT2
set DEFAULT_INITIAL_DIRECTORY=initial
set DEFAULT_RESULT_DIRECTORY=result
set DEFAULT_BATCH_DIRECTORY=bat

int csv_row_num;
int ch_num1, ch_num2;

set /a row=0
set /a is_initial=
set /a is_record=
set /a under_experiment=
set /a before_P=
set /a before_T=
set /a before_init_record_id=
set /a Nrev=

char comment[300];

FILE *fp_csv;
struct stat buff;

set /p csv_file_path="CSVファイルのパスを入力してください : "
if not exist %csv_file_path% (
    echo "CSVデータの取得に失敗しました...\n"
    exit
)

set /p home_directory_path="データが纏められているディレクトリのパスを入力してください ex) 21Axial/21data : "
if not exist %home_directory_path% (
    echo "ディレクトリの取得に失敗しました...\n"
    exit
)

set \p date_name="データ取得日を入力してください ex) 210915 : "

:loop_initial
    set \p make_initial="イニシャルファイルを作成する場合は1を、作成しないならば0を指定してください : "
    if not %make_initial% == 1 (
        if not %make_initial% == 0 echo "イニシャルファイルを作成する場合は1を、作成しないならば0を指定してください。\n"
    ) else (
        goto :exit_initial 
    )
goto :loop_initial
:exit_initial

:loop_position
    set \p position="計測した系の設定が吐出管なら1、圧縮機なら0を指定してください : "
    if not %position% == 1 (
        if not %position% == 0 echo "計測した系の設定が不正です。吐出管なら1、圧縮機なら0を指定してください。\n"
    ) else (
        goto :exit_position
    )
goto :loop_position
:exit_position

:loop_initial_sp
    set \p position_sp="静圧を測定した場所がインレットなら2を、圧縮機内部なら1を、測定しなければ指定してください。 : "
    if not %position_sp% != 2 (
        if not %position_sp% != 1 (
            if not %position_sp% != 0 echo "静圧を測定した場所の指定が不正です。インレットなら2を、圧縮機内部なら1を、測定しなければ指定してください。\n"
        )
    ) else (
        goto :exit_position_sp
    )
goto :loop_initial_sp
:exit_position_sp

input_directory_path=%home_directory_path%/%DEFAULT_DATA_DIRECTORY%/%date_name%
output_directory_path=%home_directory_path%/%DEFAULT_SORTED_DATA_DIRECTORY%/%date_name%

rem データを分割
for /f "delimis=, tokens=1-9" %%a in (%csv_file_path%) (
    if %%d == Y (
        set /a is_initial=1
    ) else (
        set /a is_initial=0
    )
    
    rem Skipする行以外を分割
    if not %%c==Y (
        sort.exe %%b %is_initial% %input_directory_path% %output_directory_path% 0 0
        if %ERRORLEVEL% equ 1 (
            echo "%b%の分割に失敗しました。"
            exit
        )
    )
)

initial_directory_path=%home_directory_path%/%DEFAULT_INITIAL_DIRECTORY%/%date_name%
result_directory_path=%home_directory_path%/%DEFAULT_RESULT_DIRECTORY%/%date_name%
batch_directory_path=%home_directory_path%/%DEFAULT_BATCH_DIRECTORY%/%date_name%

rem バッチを作成
set \a under_experiment=0
for /f "delimis=, tokens=1-9" %%a in (%csv_file_path%) (
    rem D行がYかどうかでイニシャルファイルかどうかを判定
    if %%d == Y (
        set /a is_initial=1
    ) else (
        set /a is_initial=0
    )
    
    rem B行が0かどうかでレコードしているかどうかを判定
    if %%b == 0 (
        set /a is_record=0
    ) else (
        set /a is_record=1
    )
    
    rem イニシャルかつレコードしていたら実験中かどうかを切り替える
    if %is_initial% equ 1 (
        if %is_record% equ 1 (
            if %under_experiment% equ 0 (
                set \a under_experiment=0
            ) else (
                set \a under_experiment=1
            )
        )
    )
    
    if %is_record% equ 1 (
    )
    
    rem 
    if %under_experiment% equ 0 (
        set \a before_P=%%e
        set \a before_T=%%f
        set \a Nrev=%%g
        set \a before_init_no=%%h
        set \a under_experiment=1
    ) else (
        if %is_initial% equ 1 (
            set \a before_P=%%e
            set \a before_T=%%f
            set \a Nrev=%%g
        )
    )
    
    rem Skipする行以外を分割
    if not %%c==Y (
        sort.exe %%b %is_initial% %input_directory_path% %output_directory_path% 0 0
        if %ERRORLEVEL% equ 1 (
            echo "%b%の分割に失敗しました。"
            exit
        )
    )
)
for (int i = 0; i <= TOTAL_ROW_NUM; i++){
    fn = (int)csv_data[i][ID_COL-2];
    is_skip = (int)csv_data[i][SKIP_COL-2];
    is_initial = (int)csv_data[i][INITIAL_COL-2];
    before_init = (int)csv_data[i][BEFORE_INI_COL-2];
    after_init = (int)csv_data[i][AFTER_INI_COL-2];
    before_P = csv_data[before_init][P_COL-2];
    after_P = csv_data[after_init][P_COL-2];
    before_T = csv_data[before_init][T_COL-2];
    after_T = csv_data[after_init][T_COL-2];

    ch_num1 = 0;
    ch_num2 = 0;
    if (make_bat(fn, before_init, after_init, 1, 100, input_directory_path, result_directory_path, batch_directory_path, initial_directory_path, before_P, after_P, before_T, after_T, Nrev, make_initial, position, position_sp)) {
        sprintf(comment, "%dのバッチファイル作成に失敗しました。\n", fn);
        exit_with_error(comment);
    }
}
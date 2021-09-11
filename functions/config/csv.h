#ifndef CSV
#define CSV

#define HEADER_ROW 1 // ヘッダー行

#define TOTAL_COL_NUM 10 // 総列数(配列定義用)

#define ID_COL 1 // レコード番号列
#define SKIP_COL 2 // スキップするかどうか書かれてる列
#define INITIAL_COL 3 // イニシャルかどうか書かれてる列
#define TIME_COL 4 // 経過時間列(不要)
#define P_COL 5 // 圧力列
#define T_COL 6 // 温度列
#define N_COL 7 // 回転数列
#define BEFORE_INI_COL 8 // レコード開始前のイニシャルID列
#define AFTER_INI_COL 9 // レコード開始後のイニシャルID列
#define DETAILS_COL 10 // 詳細列(不要)

int get_row_num(char* csv_file_path);
int get_csv_value(char* csv_file_path);

#endif
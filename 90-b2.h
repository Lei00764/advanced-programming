/* 2053932 软件 雷翔 */
#pragma once

const int BASIS_LINE = 1, BASIS_COL = 0;

// tools中
void to_be_continued(int choice, const int X, const int Y);

// base中
void DoByChoice2(int arr[11][11], int lines, int cols, int visited[11][11], char path[100][2], int three_ball_color[3]);  // 选项2：输入起始点坐标和目的点坐标，输出结果
void DoByChoice3(int arr[11][11], int lines, int cols, int visited[11][11], char path[100][2], int three_ball_color[3], int three_ball_position[3][2], int delete_ball_num[8]);  // 选项3
void DoByChoice45(int arr[11][11], int lines, int cols, int user_choice);  // 选项4和5
void DoByChoice67(int arr[11][11], int lines, int cols, int user_choice, int visited[11][11], char path[100][2], int three_ball_color[3], int three_ball_position[3][2], int delete_ball_num[8]);  // 选项6和7

int GetBallNumInArr(int arr[11][11], int lines, int cols);  // 返回数组中球的数量
void InputLinesCols(int& lines, int& cols);  // 输入行数和列数
void InitArrToZero(int arr[11][11]);  // 初始化数组，全部置0
void InitBallInArr(int arr[11][11], int lines, int cols, int user_chioce);  // 在数组中随机生成5个或60%个球
void InputStartEnd(int arr[11][11], int lines, int cols, int& start_line, int& start_col, int& end_line, int& end_col, int three_ball_color[3]);
int DFS(int arr[11][11], int lines, int cols, int start_line, int start_col, int end_line, int end_col, int visited[11][11], char path[100][2]); // 判断从(start_line, start_col)到(end_line, end_col)是否存在路径，如果存在返回1，不存在则返回0
int BFS(int arr[11][11], int lines, int cols, int start_line, int start_col, int end_line, int end_col, int visited[11][11], char path[100][2]); 
void InsertPoint(char path[100][2], int line, int col);  // 插在path数组最后
void RemovePoint(char path[100][2]);                     // 删除path数组最后一个点
int MoveStartToEndInArr(int arr[11][11], char path[100][2], int lines, int cols, int delete_ball_num[8]);  // 返回移动后的分数
int IsDelete(int arr[11][11], int end_line, int end_col, int lines, int cols, int delete_ball_num[8]);  // 消除5个及以上相同的球 如果有，会更改arr的值
void CreateThreeBallInArr(int arr[11][11], int lines, int cols, int three_ball_color[3], int delete_ball_num[3][2]);  // 在数组中生成三个随机颜色的球


// console中 cmd图形界面
void PrintArr(int arr[11][11], int lines, int cols);  // 在cmd窗口打印数组
void PrintSearchResult(int arr[11][11], int visited[11][11], int lines, int cols);  // 在cmd窗口打印查找结果数组和移动路径
void DrawArr1(int arr[11][11], int lines, int cols);  // 画边框和球 无分割线 
void DrawArr2(int arr[11][11], int lines, int cols);  // 有分割线
void MouseAction(int arr[11][11], int lines, int cols, int& pre_line, int& pre_col, int& cur_line, int& cur_col);  // 选项6/7 鼠标动作
int DrawMove(int arr[11][11], int lines, int cols, int start_line, int start_col, int end_line, int end_col);  // 画出移动路径
void MoveUp(int x, int y, int color);     // 画出向上移动的动画
void MoveRight(int x, int y, int color);  // 画出向右移动的动画
void MoveDown(int x, int y, int color);   // 画出向下移动的动画
void MoveLeft(int x, int y, int color);   // 画出向左移动的动画
void ShowMessage(int arr[11][11], int score, int three_ball_color[3], int lines, int cols, int deleteBall[8]);  // 显示右侧信息
void ShowScore(int cols, int score);  // 显示得分
void ShowNextBall(int cols, int three_ball_color[3]);  // 显示下3球颜色
void ShowResult(int arr[11][11], int lines, int cols, int deleteBall[8]);  // 显示结果
void DrawThreeBall(int three_ball[3][2], int three_ball_color[3]);  // 在原有的图之上画三个球
void DrawMark(int line, int col, int color);  // 置选中标记
void RecoverMark(int line, int col, int color);  // 恢复原来的标记

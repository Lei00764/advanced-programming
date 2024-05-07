/* 2053932 ��� ���� */
#pragma once

const int BASIS_LINE = 1, BASIS_COL = 0;

// tools��
void to_be_continued(int choice, const int X, const int Y);

// base��
void DoByChoice2(int arr[11][11], int lines, int cols, int visited[11][11], char path[100][2], int three_ball_color[3]);  // ѡ��2��������ʼ�������Ŀ�ĵ����꣬������
void DoByChoice3(int arr[11][11], int lines, int cols, int visited[11][11], char path[100][2], int three_ball_color[3], int three_ball_position[3][2], int delete_ball_num[8]);  // ѡ��3
void DoByChoice45(int arr[11][11], int lines, int cols, int user_choice);  // ѡ��4��5
void DoByChoice67(int arr[11][11], int lines, int cols, int user_choice, int visited[11][11], char path[100][2], int three_ball_color[3], int three_ball_position[3][2], int delete_ball_num[8]);  // ѡ��6��7

int GetBallNumInArr(int arr[11][11], int lines, int cols);  // �����������������
void InputLinesCols(int& lines, int& cols);  // ��������������
void InitArrToZero(int arr[11][11]);  // ��ʼ�����飬ȫ����0
void InitBallInArr(int arr[11][11], int lines, int cols, int user_chioce);  // ���������������5����60%����
void InputStartEnd(int arr[11][11], int lines, int cols, int& start_line, int& start_col, int& end_line, int& end_col, int three_ball_color[3]);
int DFS(int arr[11][11], int lines, int cols, int start_line, int start_col, int end_line, int end_col, int visited[11][11], char path[100][2]); // �жϴ�(start_line, start_col)��(end_line, end_col)�Ƿ����·����������ڷ���1���������򷵻�0
int BFS(int arr[11][11], int lines, int cols, int start_line, int start_col, int end_line, int end_col, int visited[11][11], char path[100][2]); 
void InsertPoint(char path[100][2], int line, int col);  // ����path�������
void RemovePoint(char path[100][2]);                     // ɾ��path�������һ����
int MoveStartToEndInArr(int arr[11][11], char path[100][2], int lines, int cols, int delete_ball_num[8]);  // �����ƶ���ķ���
int IsDelete(int arr[11][11], int end_line, int end_col, int lines, int cols, int delete_ball_num[8]);  // ����5����������ͬ���� ����У������arr��ֵ
void CreateThreeBallInArr(int arr[11][11], int lines, int cols, int three_ball_color[3], int delete_ball_num[3][2]);  // ���������������������ɫ����


// console�� cmdͼ�ν���
void PrintArr(int arr[11][11], int lines, int cols);  // ��cmd���ڴ�ӡ����
void PrintSearchResult(int arr[11][11], int visited[11][11], int lines, int cols);  // ��cmd���ڴ�ӡ���ҽ��������ƶ�·��
void DrawArr1(int arr[11][11], int lines, int cols);  // ���߿���� �޷ָ��� 
void DrawArr2(int arr[11][11], int lines, int cols);  // �зָ���
void MouseAction(int arr[11][11], int lines, int cols, int& pre_line, int& pre_col, int& cur_line, int& cur_col);  // ѡ��6/7 ��궯��
int DrawMove(int arr[11][11], int lines, int cols, int start_line, int start_col, int end_line, int end_col);  // �����ƶ�·��
void MoveUp(int x, int y, int color);     // ���������ƶ��Ķ���
void MoveRight(int x, int y, int color);  // ���������ƶ��Ķ���
void MoveDown(int x, int y, int color);   // ���������ƶ��Ķ���
void MoveLeft(int x, int y, int color);   // ���������ƶ��Ķ���
void ShowMessage(int arr[11][11], int score, int three_ball_color[3], int lines, int cols, int deleteBall[8]);  // ��ʾ�Ҳ���Ϣ
void ShowScore(int cols, int score);  // ��ʾ�÷�
void ShowNextBall(int cols, int three_ball_color[3]);  // ��ʾ��3����ɫ
void ShowResult(int arr[11][11], int lines, int cols, int deleteBall[8]);  // ��ʾ���
void DrawThreeBall(int three_ball[3][2], int three_ball_color[3]);  // ��ԭ�е�ͼ֮�ϻ�������
void DrawMark(int line, int col, int color);  // ��ѡ�б��
void RecoverMark(int line, int col, int color);  // �ָ�ԭ���ı��

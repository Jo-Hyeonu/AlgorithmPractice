#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M, K;
int minX, minY;
int strX, strY;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
//우/하/좌/상

int cx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int cy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
//8방향

struct Tower {
    int x;
    int y;
    int Attack;
    int Last;
};
Tower Map[11][11];
int Active[11][11];

void Input() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            int Attack;
            cin >> Attack;
            Map[i][j] = { i, j, Attack, 0 };
        }
}

//공격자 선정
void Select_Weak() {

    Tower Weak = { 9999, 9999, 9999, 9999 };
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            if (Map[i][j].Attack <= 0) continue;

            if (Weak.Attack > Map[i][j].Attack)
                Weak = Map[i][j];
            else if (Weak.Attack == Map[i][j].Attack)
                if (Weak.Last < Map[i][j].Last)
                    Weak = Map[i][j];
                else if (Weak.Last == Map[i][j].Last)
                    if (Weak.x + Weak.y < i + j)
                        Weak = Map[i][j];
                    else if (Weak.x + Weak.y == i + j)
                        if (Weak.y < j)
                            Weak = Map[i][j];
                       
        }

    minX = Weak.x;
    minY = Weak.y;
}


//공격 대상 선정
void Select_Strong() {

    Tower Strong = { 0, 0, 0, 0 };
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            if (Map[i][j].Attack <= 0) continue;
            
            if (Strong.Attack < Map[i][j].Attack)
                Strong = Map[i][j];
            else if (Strong.Attack == Map[i][j].Attack)
                if (Strong.Last > Map[i][j].Last)
                    Strong = Map[i][j];
                else if (Strong.Last == Map[i][j].Last)
                    if (Strong.x + Strong.y > i + j)
                        Strong = Map[i][j];
                    else if (Strong.x + Strong.y == i + j)
                        if (Strong.y > j)
                            Strong = Map[i][j];
        }

    strX = Strong.x;
    strY = Strong.y;
}

bool End_Check() {
    int Cnt = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (Map[i][j].Attack > 0) Cnt++;
    if (Cnt == 1) return true;
    else return false;
}

//범위 초과 고려
pair<int, int> Make_Range(int x, int y) {
    int px = x;
    int py = y;

    if (px < 1) px = N;
    else if (px > N) px = 1;

    if (py < 1) py = M;
    else if (py > M) py = 1;

    return { px, py };
}

//레이저 공격 가능 여부
bool Razer(int x, int y) {

    int Visit[11][11] = { 0 };
    int Past_X[11][11] = { 0 };
    int Past_Y[11][11] = { 0 };
    bool Flag = false;

    queue<pair<pair<int, int>, int>> Q;
    Q.push({ {x, y}, 0 });
    Visit[x][y] = 1;

    //연결 가능여부
    while (!Q.empty())
    {
        int px = Q.front().first.first;
        int py = Q.front().first.second;
        int time = Q.front().second;
        Q.pop();

        if(px == strX && py == strY)
        {
            Flag = true;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = px + dx[i];
            int ny = py + dy[i];
            pair<int, int> next = Make_Range(nx, ny);
            nx = next.first;
            ny = next.second;
            //nx, ny 좌표 변환

            if (Visit[nx][ny] == 1) continue;        //방문 타워
            if (Map[nx][ny].Attack <= 0) continue;   //부숴진 타워

            Visit[nx][ny] = 1;
            Past_X[nx][ny] = px;
            Past_Y[nx][ny] = py;
            Q.push({ {nx, ny}, time + 1 });
        }
    }

    //공격 감행
    if(Flag == true)
    {
        Map[strX][strY].Attack -= Map[minX][minY].Attack;
        Active[strX][strY] = 1;

        int cx = Past_X[strX][strY];
        int cy = Past_Y[strX][strY];
        Active[cx][cy] = 1;

        while(!(cx == minX && cy == minY))
        {
            Map[cx][cy].Attack -= (Map[minX][minY].Attack / 2);
            int next_x = Past_X[cx][cy];
            int next_y = Past_Y[cx][cy];
            cx = next_x;
            cy = next_y;
            Active[cx][cy] = 1;
        }
    }

    return Flag;
}

void Bomb_Attack(int x, int y) {
    Map[x][y].Attack -= Map[minX][minY].Attack;
    Active[x][y] = 1;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + cx[i];
        int ny = y + cy[i];
        pair<int, int> next = Make_Range(nx, ny);
        nx = next.first;
        ny = next.second;
        // 좌표 변환

        if (nx == minX && ny == minY) continue;  //공격자 제외
        if (Map[nx][ny].Attack <= 0) continue;   //부숴진 영역 제외

        Map[nx][ny].Attack -= (Map[minX][minY].Attack / 2);
        Active[nx][ny] = 1;
    }
}

void Heal() {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            if (i == minX && j == minY) continue; //공격자
            if (i == strX && j == strY) continue; //공격대상
            if (Map[i][j].Attack <= 0) continue;  //이미 부숴짐
            if (Active[i][j] == 1) continue;
            //공격 경료
            Map[i][j].Attack += 1;
            //1씩 증가
        }
}

void Clear() {
    minX = 0; minY = 0;
    strX = 0; strY = 0;
    memset(Active, 0, sizeof(Active));
}

int main() {
    Input();
    int Time = 1;
    while (Time <= K)
    {
        //1.공격자 선정
        Select_Weak();

        //2.공격대상 선정
        Select_Strong();

        Map[minX][minY].Attack += (N + M);
        Map[minX][minY].Last = Time;

        //3.레이저 공격/폭탄 공격 시도
        bool Razer_Attack = Razer(minX, minY);
        if(Razer_Attack == false)
        {
            Bomb_Attack(strX, strY);
        }

        //종료 상황 체크
        if (End_Check() == true) break;

        //4.포탑 정비
        Heal();
        Clear();
        Time++;
    }

    Select_Strong();
    cout << Map[strX][strY].Attack;

}
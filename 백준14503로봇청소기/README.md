# [백준14053] 로봇청소기

- URL :  https://www.acmicpc.net/problem/14503
- 출처 :  삼성전자 역량테스트 기출



## 개요

> 목표

N * M 행렬에서 로봇 청소기가 청소하는 칸의 개수를 출력하자!



> 제약조건
1.  현재 위치를 청소한다.
2.  현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
</br>
    2-1.  왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
</br>
    2-2.  왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
</br>
    2-3.  네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, **바라보는 방향을 유지한 채로 한 칸 후진**을 하고 2번으로 돌아간다.
</br>
    2-4.  네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
</br>
   
- 3 ≤ M,N ≤ 50
- d가 0인 경우에는 북쪽을, 1인 경우에는 동쪽을, 2인 경우에는 남쪽을, 3인 경우에는 서쪽
- 빈 칸은 0, 벽은 1
- 지도의 첫 행, 마지막 행, 첫 열, 마지막 열에 있는 모든 칸은 벽이다.
- 로봇 청소기가 있는 칸의 상태는 항상 빈 칸이다.




## 회고

해당 문제는 전형적인 시뮬레이션 문제로써 문제에서 요구하는 조건들을 **정확히** 구현한다면 큰 문제없이 통과할 것으로 예상했습니다.

그런데 한 번 실패를 하였는데,
이유는 뒤로 후진하기 전(실제 좌표값에 적용하기전)에 가능한지 여부를 먼저 검사하지 않고 움직였습니다.




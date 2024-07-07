//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"header.h"
using namespace std;

/*
단축키

디버그

F5 : 디버깅 시작
Ctrl + F5 : 디버그 하지 않고 시작
Seift + F5 : 디버깅 중지
F9 : 중단점 설정, 해제
F11 : 한 단계씩 코드 실행

편집

Ctrl + k + f : 자동 정렬
Ctrl + Space, Tab : 자동 완성
Ctrl + d : 한 줄 복사
Ctrl + k + c : 주석 처리
Ctrl + k + u : 주석 해제
Ctrl + u : 소문자 변환
Ctrl + Seift + u : 대문자 변환
Ctrl + Shift + f : 문자 찾기
Alt + ↑ / ↓ : 한 줄 올리기, 내리기
Alt + 마우스, Alt + Seift + ↑ / ↓ : 열 단위 편집
Ctrl + M + O ; 모든 주석 및 함수 닫기
Ctrl + Alt ; 여러줄에 대해 동일한 동작 수행
Ctrl + Enter ; 윗줄에 라인 추가
/// ; summary 달 수 있음
*/


int main()
{
	//cout << "Stack Test Result \n";
	//main_stack_stl(); //240625 #1 Stack stl
	//main_stack(); // 210424 #1 Stack

	//cout << "Queue Test Result \n";
	//main_queue_stl(); // 240625 #2 Queue stl
	//main_queue(); // 210425 #2 Queue

	cout << "Heap Test Result \n";
	main_Heap_stl(); // 240626 #3 Priority Queue stl
	//main_Heap(); // 210430 #3 Priority Queue
	//main_Heap_ss(); // 210430 #3 Priority Queue
	////main_Heap(int argc, char* argv[]); // 210430 #3 Priority Queue

	//cout << "Tree Test Result \n";
	//main_Tree(); // 210514 #4 Tree

	//cout << "Graph Test Result (삼성문제:각 쿼리 정점과 인접한 정점들 출력) \n";
	//main_Graph(); //210608 #5 Graph

	//cout << "Tree and Query Test Result (백준문제:각 쿼리 정점을 포함한 SubTree 정점 갯수 출력) \n";
	//main_tree_and_query(); //210608 #5 Graph

	//cout << "Linkedlist Test Result \n";
	//main_Linkedlist();// 210511 #6 Linked List
	//main_Linked_list_ss();

	//★이해안됨
	//cout << "Hash Test Result \n";
	//main_hash(int argc, char* argv[]); //210514 #7 Hash

	//★내것안됨
	//cout << "Permutation & Combination \n";
	//main_Permu_Combi();

	//cout << "Fibonacci & Factorial Recursion \n";
	//main_recursion();

	//cout << "DP : Sticker \n";
	//main_dp_sticker();

	//★이해안됨
	//cout << "Quick Sort (퀵정렬) \n";
	//main_quick_sort();

	//★이해안됨
	//cout << "Insert Sort (삽입정렬) \n";
	//main_insert_sort();

	//★이해안됨
	//cout << "Binary Search (이분탐색) \n";
	//main_binary_search();
	//main_bs_tree();

	//cout << "DFS (깊이우선탐색) \n";
	//main_dfs_basic();

	//cout << "BFS (너비우선탐색) \n";
	//main_bfs_basic();

	//cout << "DFS (Nqueen) \n";
	//main_dfs_nqueen();

	//cout << "DFS (단지번호붙이기) \n";
	//main_village();

	//cout << "DFS (내리막길) \n";
	//main_underpath();
	
	//main_dp_sticker(); // #10_DP_Sticker
	
	//main_dp_tree_vil(); //#10_DP_Tree_우수마을
	
	//main_dp_top(); // #10_DP_상징물최대높이_최대탑
	
	//main_dp_making1(); // #10_DP_1로만들기

	//main_coin2(); // #10_동전2
	
	return 0;
}




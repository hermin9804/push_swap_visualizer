# push_swap_visualizer

## Note

- push_swap 보너스 과제인 checker 프로그램을 응용해서 만든 간단한 push_swap_visualizer 프로그램입니다.
- 인자로 들어가는 난수는 minckim님의 [push_swap_tester](https://github.com/minckim42/push_swap_tester) repo에 있는 random_numbers 프로그램을 사용 했습니다.
- 오류나 버그, 궁금한점은 슬랙 DM 혹은 메일로 연락 주세요!
- 수정이나 배포는 자유 입니다!

## Directory
```
|
|- [ push_swap ] (Your push_swap dir)
|		|- Makefile
|
|- [ push_swap_visuzlizer ]
|		|- run_visualizer.bash
|		|- push_swap_tester (push_swap_tester by minckim)
|		|- Makefile
|
```

## Usage

- push_swap 디렉토리 명이 ```push_swap```이 아니면 bash 파일에 적힌 ```push_swap``` 경로를 본인의 디렉토리로 교체하거나 디렉토리명을 ```push_swap```으로 바꿔주세요.
- push_swap 디렉토리와 push_swap_visualizer 디렉토리 에서 각각 ```make``` 를 실행시켜주세요.
- ./run_visualizer.bash <숫자 개수>
- <숫자 개수> 를 입력 하지 않은 경우 기본값으로 10 이 들어가게 됩니다.
- 프로그램이 실행된 후 ```\n``` 을 입력 할때마다 하나의 연산을 수행하게 됩니다.

## Example
```
./run_visualizer.bash
```

```
./run_visualizer.bash 30
```

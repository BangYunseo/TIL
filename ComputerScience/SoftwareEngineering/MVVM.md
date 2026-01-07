# MVVM

> [참고 자료](https://beomy.tistory.com/43)
>
> 1절. MVVM
>
> 2절. MVVM 요소

## 1절. MVVM

### MVVM 패턴

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/SoftwareEngineering/Image/MVVM/01_MVVM.PNG" height="auto" />

- Model + View + ViewModel
- 프로그램의 비즈니스 & 프레젠테이션 로직을 UI로 분리하는 패턴
- Command 패턴 + Data Binding을 통해 View와 View Model 사이의 의존성 제거
- View Model과 View는 1 : n 관계

### 동작

1. 사용자의 Action들이 View를 통해 입력
2. View에 Action이 들어올 시 Command 패턴으로 View Model에 Action 전달
3. View Model이 Model에 데이터 요청
4. Model이 View Model에 요청받은 데이터 응답
5. View Model이 응답 받은 데이터 가공 후 저장
6. View는 View Model과 Data Binding 후 화면 표시

### 장점

- 로직 분리로 생산성 향상
  - UI 없이 개발 가능
- 의존성이 없어 수월한 단위 테스트
- 각각의 독립적인 부분으로 모듈화하여 개발 가능

### 단점

- 복잡한 설계
  - RX, 데이터 바인딩에 대한 이해 필요
  - ViewModel 설계의 복잡성
- 뷰 모델이 비대해질 확률 증가
- 데이터 바인딩으로 인해 심한 메모리 소모

## 2절. MVVM 요소

### View

> 사용자에게 보여지는 UI

- 사용자 인터페이스, 화면 제공
- 사용자 입력 처리
- XAML과 비슷한 Markup 언어로 디자인

### ViewModel

> View 표현을 위한 Model로 데이터 처리도 수행

- View 이벤트 감지 후 비즈니스 로직 수행
- Model과 상호작용 후 View에 데이터 업데이트
- View에 표시할 데이터를 가공해 제공

### Model

> 프로그램에서 사용데는 데이터와 그 데이터를 처리하는 부분

- 데이터와 비즈니스 로직 담당
- 데이터 Save & Load
- 데이터 소스와 상호작용
  - 데이터베이스
  - 네트워크 요청
  - 파일 시스템

(필요 시 작성
// 커맨드 패턴
https://ko.wikipedia.org/wiki/%EC%BB%A4%EB%A7%A8%EB%93%9C_%ED%8C%A8%ED%84%B4

// 데이터 바인딩
https://en.wikipedia.org/wiki/Data_binding)

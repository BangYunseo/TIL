# MVVM

> 1절. MVVM 패턴
>
> 2절. MVVM 요소
>
> 3절. ViewModel
>
> 4절. Model

## 1절. MVVM 패턴

### MVVM 패턴

<img src="https://github.com/BangYunseo/TIL/blob/main/ComputerScience/SoftwareEngineering/Image/MVVM/01_MVVM.PNG" height="auto" />

- Model - View - ViewModel 의 약자
- 프로그램의 비즈니스 & 프레젠테이션 로직을 UI로 분리하는 패턴

### 장점

- 로직 분리로 생산성 향상
  - UI 없이 개발 가능
- 수월한 단위 테스트
  - 의존성이 없기 때문

### 단점

- 복잡한 설계
  - RX, 데이터 바인딩에 대한 이해 필요
  - ViewModel 설계의 복잡성
- 뷰 모델이 매우 커질 확률 증가
- 데이터 바인딩으로 인해 심한 메모리 소모

## 2절. MVVM 요소

### View

- 사용자 인터페이스, 화면 제공
- 사용자 입력 처리
- XAML과 비슷한 Markup 언어로 디자인

### ViewModel

- View 이벤트 감지 후 비즈니스 로직 수행
- Model과 상호작용 후 View에 데이터 업데이트
- View에 표시할 데이터를 가공해 제공

### Model

- 데이터와 비즈니스 로직 담당
- 데이터 Save & Load
- 데이터 소스와 상호작용
  - 데이터베이스
  - 네트워크 요청
  - 파일 시스템

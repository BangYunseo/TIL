# Chapter 12. rigidbody component

> [참고영상](https://www.youtube.com/watch?v=Y3xkgpCukow)
>
> [프로젝트](https://github.com/BangYunseo/)
> 
> 1절. rigidbody
>
> 2절. 인터페이스
>
> 3절. 에디터
>
> 4절. 게임 구조



## 1절. rigidbody

#### rigidbody

- 유니티의 컴포넌트(component)
- 유니티의 물리 엔진에 해당
- 유니티 Transform 조작 가능

![ch12-01-interface](https://github.com/BangYunseo/TIL/blob/main/GameEngine/Unity/Image/ch12/ch12-01-interface.PNG)

- 아래에 바닥을 두고 실행시킬 경우, 물리 엔진 적용 모습 확인 가능

#### component
- "Rigidbody는 Component지만 Behaviour은 아니다"
    - Behaviour는 유니티의 클래스
    - 컴포넌트로부터 상속

[유니티 스크립팅 API](https://coderzero.tistory.com/entry/%EC%9C%A0%EB%8B%88%ED%8B%B0-%EC%8A%A4%ED%81%AC%EB%A6%BD%ED%8C%85-API-%EA%B8%B0%EB%B3%B8Object-Component-Behaviour-MonoBehaviour)

- 행동의 자식 클래스들은 인스펙터에서 사용할 지 여부 설정 가능

#### rigidbody with 2D

- Unity 3D는 Nvidia Physx 사용
- Box2D는 2D 물리 엔진 사용
- 구현 방식의 차이 존재

#### Scene에서의 구현

- Speed, Velocity, Tensors 존재

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
- 유니티 Transform 제어 
- 중력(gravity)과 충돌(collision) 반응

![ch12-01-interface](https://github.com/BangYunseo/TIL/blob/main/GameEngine/Unity/Image/ch12/ch12-01-interface.PNG)

- 아래에 바닥을 두고 실행시킬 경우, 물리 엔진 적용 모습 확인 가능

#### component
- "Rigidbody는 Component지만 Behaviour은 아니다"
    - Behaviour는 유니티의 클래스
    - 컴포넌트로부터 상속
    - 활성화 / 비활성화 불가능

[유니티 스크립팅 API](https://coderzero.tistory.com/entry/%EC%9C%A0%EB%8B%88%ED%8B%B0-%EC%8A%A4%ED%81%AC%EB%A6%BD%ED%8C%85-API-%EA%B8%B0%EB%B3%B8Object-Component-Behaviour-MonoBehaviour)


#### 주요 속성

|속성|내용|
|:---:|:---|
|Mass(질량)|더 큰 질량을 가진 오브젝트가 더 작은 질량의 오브젝트를 밀쳐내지만 낙하 속도에는 영향 없음|
|Linear Drag / Angular Drag(선형/회전 저항)| 오브젝트의 속도 감소 역할|
|Use Gravity(중력 사용)|중력을 적용할 지 결정하며 Rigidbody2D에서는 Gravity Scale로 대체|
|Is Kinematic(운동학)|활성화 시 물리 법칙에 영향을 받지 않고 Transform을 직접 제어 가능|

- Interpolation
    - 수치해석분야의 보간법
    - 이동이 부드럽지 않은 경우 사용

|종류|내용|
|:--:|:--|
|Interpolate|이전 프레임 기준 부드럽게 적용|
|Extrapolate|다음 프레임 기준 부드럽게 적용|


- Collision Detection
    - 충돌 감지 여부 

|종류|내용|
|:--:|:--|
|Discrete(기본값)|매 물리 프레임마다 충돌 감지(Basic Way)|
|Continuous(연속)|빠른 오브젝트의 충돌 감지에 사용(ex : bullet, 대신 부하가 큼|
|Continuous Dynamic|동적 오브젝트간 충돌 감지(가장 비용이 큼)|
|Continuous Speculative: 충돌을 예측하는 방식으로 비용이 적지만 한계 존재|



4. Rigidbody 사용 팁

1. RequireComponent 사용:

특정 컴포넌트가 필요할 경우 RequireComponent를 사용해 null 오류 방지.



2. FixedUpdate에서 물리 연산 수행:

Update()가 아니라 FixedUpdate()에서 물리 연산을 수행해야 함.

Unity의 물리 업데이트는 기본적으로 0.02초(50Hz) 간격으로 실행됨.



3. 힘 추가 방식 (AddForce)

rigidbody.AddForce(Vector3 direction * force, ForceMode.Force);

rigidbody.AddRelativeForce(Vector3 direction * force, ForceMode.Force);

ForceMode.Force: 지속적인 힘 적용 (일반 이동).

ForceMode.Impulse: 순간적인 힘 적용 (넉백, 점프).

ForceMode.Acceleration: 질량을 무시하고 가속력 적용.

ForceMode.VelocityChange: 즉각적인 속도 변화 (부스트, 브레이크 등).



4. Transform을 직접 변경하지 말 것

Rigidbody의 물리 연산과 충돌할 수 있으므로 Transform을 직접 수정하지 말고 AddForce 등을 사용할 것.



5. Kinematic Rigidbody 활용

벽에 붙거나 특정 위치에 고정시키고 싶을 때 Kinematic을 사용.



6. 플랫폼 게임에서 점프와 낙하 조정

Rigidbody2D에서는 Gravity Scale을 조절하면 점프 높이와 낙하 속도를 조절할 수 있음.

3D에서는 추가적인 아래쪽 힘을 적용해야 자연스러운 낙하 구현 가능.



7. Velocity 직접 설정 가능하지만 권장되지 않음

rigidbody.velocity = new Vector3(x, y, z);

직접 설정하면 현실적인 물리 연산이 적용되지 않을 수 있음.




5. 게임 디자인 팁

현실적인 물리 법칙을 고집하지 말 것!

예를 들어, Hollow Knight 같은 게임에서의 점프는 현실적이지 않지만 재미있음.

Gravity Scale 조정 및 속도 조절로 원하는 감각을 만들어야 함.
#### rigidbody with 2D

- Unity 3D는 Nvidia Physx 사용
- Box2D는 2D 물리 엔진 사용
- 구현 방식의 차이 존재

#### Scene에서의 구현

- Speed, Velocity, Tensors 존재

# Chapter 12. rigidbody component

> [참고영상](https://www.youtube.com/watch?v=Y3xkgpCukow)
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
|Continuous Speculative|충돌을 예측하는 방식으로 비용이 적지만 한계 존재|



#### 사용 팁

##### 1) RequireComponent 사용

- 특정 컴포넌트가 필요할 경우 RequireComponent를 사용해 null 오류 방지

##### 2) FixedUpdate에서 물리 연산 수행

- Update()가 아닌 FixedUpdate()에서 물리 연산 수행
- Unity 물리 업데이트는 0.02초(50Hz) 간격

##### 3) AddForce 방식

```C#
rigidbody.AddForce(Vector3 direction * force, ForceMode.Force);
rigidbody.AddRelativeForce(Vector3 direction * force, ForceMode.Force);
```

|함수|내용|
|:--:|:--|
|ForceMode.Force|지속적인 힘(일반 이동)|
|ForceMode.Impulse|순간적인 힘(넉백, 점프)|
|ForceMode.Acceleration|질량을 무시하고 가속력 적용|
|ForceMode.VelocityChange|즉각적인 속도 변화 (부스트, 브레이크 등)|


##### 4) Transform을 직접 변경하지 금지

- Rigidbody의 물리 연산과 충돌 가능성 존재
- Transform을 직접 수정하지 말고 AddForce 사용


##### 5) Kinematic Rigidbody 활용

- 벽에 붙거나 특정 위치에 고정시키고 싶은 경우


##### 6) 플랫폼 게임에서 점프 및 낙하 조정

- Rigidbody2D
    - Gravity Scale로 점프 높이, 낙하 속도 조절 가능

- Rigidbody3D
    - 추가적인 아래쪽 힘을 적용해야 자연스러운 낙하 구현 가능



##### 7) Velocity 직접 설정 금지

```C#
rigidbody.velocity = new Vector3(x, y, z);
```

- 직접 설정 시 현실적인 물리 연산이 적용 불가 가능성 존재



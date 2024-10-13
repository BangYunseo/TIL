#  Chapter 0. 네트워크 프로토콜 개요
> 1절. 인터넷과 프로토콜
>
> 2절. 네트워크 엣지
>
> 3절. 네트워크 코어
>
> 4절. 성능
>
> 5절. 프로토콜 계층
>
> 6절. 서비스 모델

## 1절. 인터넷과 프로토콜
#### 인터넷(Internet) : "너트와 볼트(Nuts And Bolts)"의 관점
* 장치끼리 꼭 들어맞는 연결의 통신 형태
![Internet](https://github.com/BangYunseo/TIL/blob/main/Communication/NetworkProtocol/Image/ch00/Internet.PNG)

* 수십억 대의 연결된 컴퓨팅 장치
    * 호스트 = end systems
    * 인터넷의 "주변(edge)"에서 네트워크 애플리케이션 실행
* 패킷 스위치: 패킷(chunks of data)을 전달
    * 라우터, 스위치
* 통신 링크
    * 광섬유, 구리, 라디오, 위성
    * 전송 속도 : 대역폭(bandwidth)
* 네트워크
    * 장치, 라우터, 링크의 조합 : 조직에 의해 관리
* 인터넷 : 상호 연결(Network of Networks)
    * 상호연결된 ISP들
* 프로토콜(Protocol)은 어디에나 존재
    * 메세지의 송-수신 제어
    * 웹(HTTP), 스트리밍 비디오, Skype, TCP, IP, Wifi, 4G, 이더넷
* 인터넷 표준
    * RFC : 의견 요청(Request for Comments)
    * IETF : 인터넷 엔지니어링 태스크 포스(Internet Engineering Task Force) 

* ISP : Internet Service Provider(통신사)

#### 인터넷(Internet) : "서비스(Services)"의 관점
* 
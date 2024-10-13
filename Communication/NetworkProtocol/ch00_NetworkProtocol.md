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
    * 예시
        * 웹(HTTP)
        * 스트리밍 비디오
        * Skype
        * TCP
        * IP
        * Wifi
        * 4G
        * 이더넷
* 인터넷 표준
    * RFC : 의견 요청(Request for Comments)
    * IETF : 인터넷 엔지니어링 태스크 포스(Internet Engineering Task Force) 

* ISP : Internet Service Provider(통신사)

#### 인터넷(Internet) : "서비스(Services)"의 관점
* 응용 프로그램에 서비스를 제공하는 인프라
    * 웹
    * 스트리밍 비디오
    * 멀티미디어 화상회의 
    * 이메일
    * 게임
    * 전자 상거래
    * 소셜 미디어
    * 상호 연결된 기기
* 분산 응용 프로그램을 위한 프로그래밍 인터페이스 제공
    * 인터넷 전송 서비스를 사용하여 송수신 애플리케이션이 "연결"할 수 있도록 하는 "훅(Hooks)" 제공
* 우편 서비스와 유사한 서비스 옵션 제공

#### 프로토콜(Protocol)
* 네트워크 구성요소 간 보내고 받게 되는 메세지들에 대한 형식과 절차
* 메세지를 보내고 받을 때 취해지는 행동 정의

#### 네트워크 프로토콜
* 인간이 아닌 컴퓨터(기기)들이 통신 수행
* 인터넷의 모든 통신 활동은 프로토콜에 의해 관리

##### 네트워크에서의 프로토콜 정의
* 네트워크 간의 엔티티들이 주고받는 메시지의 형식, 순서, 그리고 메시지 전송 및 수신 시 취할 행동을 정의

![PP](https://github.com/BangYunseo/TIL/blob/main/Communication/NetworkProtocol/Image/ch00/PP.PNG)

## 2절. 네트워크 엣지
#### 네트워크 엣지(Network Edge)란?
* 호스트(hosts)
    * 클라이언트와 서버
* 서버(servers)
    * 주로 데이터 중앙에 위치

![NE](https://github.com/BangYunseo/TIL/blob/main/Communication/NetworkProtocol/Image/ch00/NE.PNG)

#### 접속 네트워크 및 물리적 매체

* 유선 및 무선 통신 링크

## 3절. 네트워크 코어
#### 네트워크 코어(Network Core)란?
* 상호연결된 라우터(Routers)
* 네트워크들의 네트워크(Network of Networks)

#### 최종 시스템을 엣지 라우터(Edge Router)에 연결하는 방법
* 주거용 접속 네트워크
    * 가정에서 인터넷에 연결하는 네트워크
* 기관 접속 네트워크
    * 학교, 회사 등의 기관에서 사용하는 네트워크
* 모바일 접속 네트워크
    * WiFi, 4G/5G와 같은 무선 네트워크

#### 접근 네트워크 : 케이블 기반 접속(Cable-Based Access)

![AN](https://github.com/BangYunseo/TIL/blob/main/Communication/NetworkProtocol/Image/ch00/AN.PNG)

* HFC(하이브리드 섬유 동축)
    * 비대칭(Asymmetric)
        * 최대 40 Mbps에서 1.2 Gbps의 다운로드 전송 속도 
        * 30-100 Mbps의 업로드 전송 속도
* 케이블과 섬유로 구성된 네트워크가 가정을 ISP 라우터에 연결
    * 가정집에서는 케이블 헤드엔드에 대한 접속 네트워크 공유

#### 무선 접속 네트워크(Wireless Access Networks)
* 공유 무선 접속 네트워크가 최종 시스템을 라우터에 연결
    * 기지국(Access Point)을 통한 연결

##### 무선 근거리 네트워크(WLANS)
* Wireless Local Area Networks
* 일반적으로 건물 내 또는 주변에서 사용(약 100피트 범위)
* 802.11b/g/n (WiFi) : 각각 11, 54, 450 Mbps의 전송 속도 제공

##### 광역 Cell단위 접속 네트워크(이동통신)
* Wide-area Cellular Access Networks
* 모바일, 셀룰러 네트워크 운영자가 제공(수 십 km 범위)
* 수십 Mbps의 속도
* 4G Cell 단위 네트워크(5G도 도입)
## 4절. 성능
## 5절. 프로토콜 계층
## 6절. 서비스 모델
# Chapter 9. 데이터 링크 층(Data-Link Layer)

> 0절. 개요
>
> 1절. 링크 계층 주소

## 0절. 개요

### 인터넷(Internet)

- 라우터나 스위치와 같은 장치들이 연결된 네트워크 조합
- 패킷을 호스트에서 다른 호스트로 전달하는 경우 네트워크들을 통과하는 경로 필요

### 노드와 링크

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch09/ch09-01-NodeLink.PNG" height="auto"/>

- 데이터 링크 층의 통신 : 노드-대-노드(Node-To-Node)
- LAN과 WAN : 라우터를 통한 연결
- 노드(Node) : 2개의 종단 호스트와 라우터
- 링크(Link) : 두 노드 사이 네트워크

### 서비스

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch09/ch09-02-DLL.PNG" height="auto"/>

- 데이터 링크 층
  - 프레임 짜기, 흐름 제어, 오류 제어, 혼잡 제어
  - 물리 계층(1계층)과 네트워크 층(3계층) 사이 위치
    - 물리층으로부터 서비스를 제공받음
    - 네트워크 층에 서비스 제공

### 두 가지 범주의 링크

1. 점-대-점(Point-To-Point) 링크
   - 전송 매체의 모든 성능 사용
   - 서로 연결된 두 개의 단말에만 전념
2. 브로드캐스트(BroadCast) 링크
   - 링크 성능의 일부 사용
   - 몇 개의 기기 쌍 사이에서 공유

### 두 개의 부 계층

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch09/ch09-03-DLCMAC.PNG" height="auto"/>

1. 데이터 링크 제어(DLC : Data-Link Control)
   - 점-대-점과 브로드캐스트 링크와 연관된 모든 사항 제어
2. 매체 접근 제어(MAC : Media Access Control)
   - 브로드캐스트 링크의 특별 사항 제어

## 1절. 링크 계층 주소

### 링크 계층 주소(Link-Layer Address)

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch09/ch09-04-LLA.PNG" height="auto"/>

- 링크 계층 주소(link-layer address)

  - 링크 주소(link address)
  - 물리 주소(physical address)
  - MAC 주소 (MAC address)

- IP 주소 특징

  - 발신지와 목적지 IP 주소 존재
  - 두 종단을 정의하지만 패킷이 경유하는 경로 정의 불가

- 비연결형(connectionless) 상호연결 네트워크
  - 두 노드의 링크 계층 주소의 결정 : 다른 주소지정 메커니즘 필요
- 데이터그램이 네트워크 층에서 데이터-링크 층으로 전달되는 경우
  - 프레임에 캡슐화되고 두 데이터 링크 주소는 프레임 헤더에 추가

### 세 가지 유형의 주소

1. 유니캐스트 주소
2. 멀티캐스트 주소
3. 브로드캐스트 주소

#### 유니캐스트 주소

- 일-대-일 통신
- 유니캐스팅
- 유니캐스트 주소 목적지를 갖는 프레임은 링크에서 하나의 장치와 연결

#### 멀티 캐스트

- 일-대-다 통신
- 로컬 링크로 범위 제한

#### 브로드캐스트 주소

- 일-대-전체 통신
- 목적지가 브로드캐스트 주소인 프레임은 링크 내 모든 장치로 전달

### 주소 변환 프로토콜(ARP : Address Resolution Protocol)

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch09/ch09-05-ARP.PNG" height="auto"/>

- IP 주소를 지정된 링크 계층 주소에 매핑 후 데이터링크 층으로 전달
- 네트워크 층에서 정의한 보조 프로토콜 중 하나
- 다음 노드의 IP 주소는 링크 내 프레임 이동 시 도움 X
- 다음 노드의 링크 계층 주소의 필요성 증가로 생긴 프로토콜

### 주소 변환 프로토콜 동작 과정

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch09/ch09-06-ARPP.PNG" height="auto"/>

### ARP 패킷 형식

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch09/ch09-07-ARPF.PNG" height="auto"/>

- 하드웨어 유형(hardware type) 필드
  - 링크 계층 프로토콜 유형
  - 이더넷의 경우는 1
- 프로토콜 유형(protocol type) 필드
  - 네트워크 계층 프로토콜
  - IPv4 프로토콜은 (0800)16
- 하드웨어 길이
  - 물리 주소 바이트 수
  - 이더넷의 경우는 6
- 프로토콜 길이
  - 논리 주소 바이트 수
  - IPv4의 경우는 4
- 동작(Operation)
  - Packet 타입
  - 요청(Request)의 경우는 1
  - 응답(Reply)의 경우는 2
- 발신지 하드웨어 주소 & 발신지 프로토콜 주소
  - 송신자 링크 계층과 네트워크 계층 주소 정의
- 목적지 하드웨어 주소 & 목적지 프로토콜 주소
  - 수신자 링크 계층과 네트워크 계층 주소 정의

### 통신 예제

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch09/ch09-08-Q1.PNG" height="auto"/>

- 앨리스가 데이터그램을 인터넷에서 세 노드 건너의 밥에게 전달하려고 한다.
- 앨리스는 밥의 네트워크 층 주소를 DNS(Domain Name System)으로 탐색해야 한다.

#### 앨리스 동작

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch09/ch09-09-AW.PNG" height="auto"/>

#### 라우터 R1 동작

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch09/ch09-10-R1W.PNG" height="auto"/>

#### 라우터 R2 동작

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch09/ch09-11-R2W.PNG" height="auto"/>

#### 밥 동작

<img src = "https://github.com/BangYunseo/TIL/blob/main/Communication/DataCommunication/Image/ch09/ch09-12-BW.PNG" height="auto"/>

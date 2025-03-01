# HTML Introduce

> '쉽게 배우는 HTML5 & CSS & JavaScript' 4장 내용
>
> 1절. 구조
>
> 2절. 태그

## 1절. 구조

#### HTML 기본 구조

```HTML
<!doctype html>             <!-- HTML5에 사용 -->
<HTML>                      <!-- HTML 문서 시작 -->
  <HEAD>                    <!-- 머리말 시작 / 웹 페이지에 대한 대략적인 정보 삽입 -->
    <TITLE>
                            <!-- 문서의 제목 입력/ 브라우저 상단의 제목 줄 표시 -->
    </TITLE>
  </HEAD>                   <!-- 머리말 끝 -->
  <BODY>                    <!--문서의 본문 시작-->
    <!-- 태그와 배경색, 배경이미지, 본문 글자색 등의 속성 지정 가능 / 태그 사이에는 홈페이지 내용 삽입 -->
  </BODY>                   <!--문서의 본문 끝-->
</HTML>                     <!-- HTML 문서 끝 -->
```

#### 태그(element, 지시자, 요소) 정의

- HTML 문서의 모양과 행동 양식을 정하는 하나의 명령어

- 일반적으로 <시작 태그>, </종료 태그>의 짝 형태

##### 태그 형식

1. <태그> 문장 </태그>

```HTML
<H1> Welcome to my Web Site! :D </H1>
```

2. <태그 속성(attribute) = "값"> 문장 </태그>

```HTML
<FONT COLOR = "BLACK" SIZE = "4"> 오늘의 소식 </FONT>
```

3. <태그>

```HTML
<FONT COLOR = "BLACK" SIZE = "4"> 오늘의 소식 </FONT>
```

#### 속성(attribute) 정의

- HTML 태그의 부가적인 정보 제공

- 속성 = "값" 형

##### 속성 형식

1. <태그 속성(attribute = "값")> 문장 < /태그>

```HTML
<FONT COLOR = "BLUE" SIZE = "6"> 나는 바다가 좋아 </FONT>
<H1 align = "center" style = "color : green" title = "문단1"> 경포대놀러가고오십당ㅜ.ㅜ </H1>
```

## 2절. 태그

#### <TITLE></TITLE> 태그

- 브라우저 상단의 제목 표시
- 자신의 웹 페이지를 대표할 만한 제목 간결하게 표현
- 검색엔진에서는 사용자의 검색어가 TITLE 태그에 들어있다면 해당 검색어에 높은 순위 부여

#### HTML(HyperText Markup Language)

- WWW(World Wide Web : 월드 와이드 웹)에서 하이퍼텍스트 문서를 작성하는 기본 언어

- 하이퍼 텍스트 작성을 위해 개발

- 월드 와이드 웹을 통해 볼 수 있는 웹 페이지를 만들 때 사용하는 프로그래밍 언어

- 확장자 : html, htm

- HTML 문서 : HTML로 작성된 문서

- HTML 문서는 웹 브라우저가 해석하여 이용자에게 제공

- 문서 글꼴 크기, 글꼴 색, 글꼴 모양, 그래픽, 문서이동(하이퍼링크) 등을 정의하는 명령어

- 홈페이지를 작성할 경우 사용

- 문서가 별도의 코드(code)를 인식하여 완벽한 하이퍼텍스트를 만들 뿐만 아니라 단어 또는 단문을 인터넷의 다른 장소나 파일로의 연결 가능

##### tag(태그)

- HTML에서 사용하는 명령어

- 일반적으로 시작과 끝을 표시하는 2개의 쌍으로 구성

##### Markup Language

- 문서(웹 페이지)가 화면에 표시되는 형식을 정의한 언어

- EX) 헤드라인 1

```html
<h1>한국대학교</h1>

<!--"한국대학교"를 헤드라인 1로 표시하라는 형식을 정의한 형태-->
```

#### FTP(File Trasfer Protocol)

- 인터넷에서 파일을 주고받기 위해 정한 파일 송수신 프로토콜

- 파일 송수신을 위한 규약

- 웹 호스팅 업체를 통해 호스팅 서비스를 신청한 후 자신이 만든 웹 문서(파일)을 올리기 위해 웹 호스팅 업체의 웹 서버에 접속하여 파일을 올려야 함

- FTP는 자신의 PC와 상대의 PC(웹 호스팅 업체의 서버) 간에 파일을 주고받을 경우 사용

- 즉, 서로 멀리 떨어진 PC 간에 파일을 주고받을 때 사용하는 인터넷 프로토콜

- FTP 프로토콜 : 알FTP, WS_FTP, FileZilla, WinSCP 등

#### 웹 호스팅

- 컴퓨터의 일부 용량을 할당해 사용이 가능하도록 하는 서비스

- 인터넷 임대 공간 서비스업

- 일정한 공간을 상품별로 나눠 제공

- 웹 페이지 제작 및 데이터베이스 구축 가능

- OS 및 서비스에 따라 Linux 호스팅, Windows 호스팅, 닷넷 호스팅 등으로 구분

  - 리눅스, 유닉스, 윈도우 호스팅 등은 그 서버의 운영체제에 따라 구분되며 사용자는 자신이 원하는 서버를 선택한 후 호스팅 신청 가능

- 어떤 운영체제를 선택하는지에 따라 서버가 상이

- 기본 서비스 : DB(MySQL), SSH, PHP, CGI, phpMyAdmin, PERL 등

## 2절. 인터넷 주소

#### URL(Uniform Resource Locator)

- 인터넷에서 작동하는 웹에서 자원(리소스)을 찾는 방법 제공

- 자원에 엑세스하는 데 사용되는 프로토콜의 이름과 자원의 이름 포함

  - 첫 번째 부분은 사용할 프로토콜 식별
  - 두 번째 부분은 자원이 있는 IP 주소 또는 도메인 이름 식별

- URL 프로토콜

  - 웹 자원

    - HTTP(HyperText Transfer Protocol)
    - HTTPS(HTTP Secure)

  - 전자 메일 주소

    - "mailto"
    - FTP(File Transfer Protocol)

  - 서버의 파일
    - "ftp"
    - 원격 컴퓨터에 엑세스하기 위한 세션의 텔넷

- 자원 이름

  - 서버 또는 웹 서비스를 식별하는 IP 주소 또는 도메인 이름
  - 프로그램 이름 또는 서버의 파일 경로와 이메일 주소

- 웹 사이트 주소뿐만 아니라 컴퓨터 네트워크 상의 자원을 모두 표현 가능

- EX) URL
  - https://github.com/BangYunseo
  - ftp://github.com/BangYunseo
  - mailto:yunseobang33@gmail.com

#### 도메인과 IP 주소

- 컴퓨터와 통신하기 위해 존재하는 고유한 주소 체계

- IP 주소

  - 숫자로 표현된 주소
  - ex) 218.145.31.135

- 도메인

  - 문자로 표현된 주소
  - ex) www.google.com

#### IP 주소

##### IPv4

- 32비트(4바이트)의 version4(IPv4)

- 일반적으로 도트(.)로 구분되며 4단계로 표시

- 도트로 구분된 각 숫자는 0 ~ 255까지의 숫자 사용

- 숫자로 표현된 주소는 전 세계적으로 중복되지 않음

- 형식 : nnn.nnn.nnn.nnn
  - $0 <= nnn <= 255$
  - n은 십진수

##### IPv6

- 128비트(16바이트)의 version6(IPv6)

- 32비트 IPv4의 주소 부족 현상을 대체하기 위해 주소 길이를 128비트로 늘린 새로운 버전

- 형식 : xxxx : xxxx : xxxx : xxxx : xxxx : xxxx : xxxx : xxxx
  - x는 16진수이며 4비트

##### 도메인의 사용 이유

- 인터넷 사용자들이 다른 컴퓨터와의 통신을 위해 숫자로 표현된 주소만을 사용할 경우 기억하기 어렵고 주소를 이해하기 힘듦

- 숫자로 표현된 주소(컴퓨터의 실제 주소) 대신 문자로 표현된 주소의 사용 보편화

- 즉, 도메인(Domain)의 사용이 보편화

##### 도메인(Domain)

- 인터넷에 연결된 전 세계의 어떤 컴퓨터와도 통신 가능

- 도메인의 이름은 기억, 발음하기 쉽고 문자수가 길지 않음

- 사이트의 성격을 잘 나타낼 수 있는 도메인 사용 가능

#### DNS(Domain Name Server)

- 도메인 이름을 IP 주소로 변경하기 위해 사용

- 특정 컴퓨터 또는 사으트의 주소 탐색을 위해 사람이 이해하기 쉬운 도메인 이름을 숫자 주소인 IP 주소로 변환해주는 역할

![DNS](https://github.com/BangYunseo/TIL/blob/main/Language/Web/Image/Intro/DNS.PNG)

#### 도메인 체계

![DNSsys](https://github.com/BangYunseo/TIL/blob/main/Language/Web/Image/Intro/DNSsys.PNG)

#### NIC(Network Information Center)

- 도메인 등록 및 관리하는 곳

- 각 국가 NIC에서 역할 담당

- 만약 국가의 NIC이 없는 경우 미국 NSI에서 관리

- 한국 : KRNIC
- 일본 : JPNIC

- 대표적인 도메인 등록 사이트

  - http://www.mireene.com/
  - http://www.gabia.com/
  - http://www.dothome.co.kr/

#### KRNIC(Korea Network Information Center, 한국인터넷정보센터)

- 대한민국의 인터넷 발전을 위한 기능 유지와 이용 활성화를 위해 설립된 비영리 기관

- 수행 역할

  - 인터넷 주소 관리 체제의 정립

  - 주소의 원활한 할당 및 관리

  - 인터넷 관련 국익 보호 활동

  - 기타 인터넷 이용 촉진을 위한 활동

  - IP 주소 및 도메인 등록서비스의 수행

  - 주요 정보 서비스 제공

  - ICANN, APTLD, APNIC 등과의 정보 교환

  - 업무협력

  - 기술교류

![KakaoTalk_20240918_111815281](https://github.com/user-attachments/assets/839ed7a2-1399-4acc-86e1-1b1dc237c671)


2장: 일반 규칙

프로젝트는 C 언어로 작성해야 합니다.

모든 코드는 Norm 규칙을 따라야 하며, Norm 오류가 발생하면 점수는 0점입니다.

코드에서 예상치 못한 종료(세그멘테이션 폴트, 버스 오류, 더블 프리 등) 가 발생해서는 안 됩니다.

동적 할당된 메모리는 적절히 해제해야 하며, 메모리 누수는 허용되지 않습니다.

Makefile을 제출해야 하며, 다음 규칙이 포함되어야 합니다.

$(NAME), all, clean, fclean, re, bonus

-Wall -Wextra -Werror 플래그를 사용하여 cc로 컴파일해야 하며, 불필요한 재링크(relink)를 하면 안 됩니다.

보너스를 구현할 경우, Makefile에 bonus 규칙을 추가해야 합니다.

libft를 사용할 경우, libft의 소스 코드와 Makefile을 libft 폴더에 포함해야 합니다.

테스트 프로그램을 작성하는 것이 권장되며, 제출할 필요는 없지만 방어 평가(defense)에서 유용할 수 있습니다.

Git 저장소에 제출해야 하며, 저장소에 있는 코드만 평가됩니다.


3장: 필수 구현 사항
프로그램 이름: miniRT
제출 파일: 모든 소스 코드
실행 방법:

./miniRT <scene_file.rt>
외부 함수:

open, close, read, write, printf, malloc, free, perror, strerror, exit

수학 라이브러리 (math.h)의 모든 함수 (-lm 플래그 필요)

MiniLibX의 모든 함수

프로그램 기능
MiniLibX를 사용해야 합니다. (운영 체제에서 제공되는 버전 또는 소스에서 직접 빌드 가능)
윈도우 관리가 원활해야 합니다. (창 전환, 최소화 등)
기본 기하학적 객체 3가지를 구현해야 합니다.
평면(Plane)
구(Sphere)
원기둥(Cylinder)
객체와의 교차 판정(intersection) 및 내부 처리를 올바르게 구현해야 합니다.
객체 변형 기능
구(Sphere) → 크기(지름) 조정 가능
원기둥(Cylinder) → 너비, 높이 조정 가능
이동 및 회전 변환 (단, 구와 광원은 회전 불가능)
조명 시스템
광원의 밝기 조절
그림자(하드 쉐도우)
주변광(Ambient) 및 확산광(Diffuse) 구현
이미지 출력 및 이벤트 처리
ESC 키 → 창 닫기 및 프로그램 종료
창 닫기 버튼(X) 클릭 → 프로그램 종료
MiniLibX의 이미지 기능을 사용하는 것이 권장됨
입력 파일 (.rt 확장자)의 구조
요소별 정보는 한 줄 이상 띄워도 무관함
각 요소 정보는 공백 하나 이상으로 구분됨
요소는 임의의 순서로 배치 가능
대문자로 시작하는 요소는 씬(Scene)에서 한 번만 선언 가능

예제 파일 구조 (scene.rt)

A 0.2 255,255,255  # Ambient Light: 비율 0.2, RGB(255,255,255)
C -50,0,20 0,0,1 70  # Camera: 위치(-50,0,20), 방향(0,0,1), FOV 70
L -40,0,30 0.7 255,255,255  # Light: 위치(-40,0,30), 밝기 0.7, RGB(255,255,255)

pl 0,0,0 0,1,0 255,0,225  # Plane: 좌표(0,0,0), 법선(0,1,0), 색상(255,0,225)
sp 0,0,20 20 255,0,0  # Sphere: 중심(0,0,20), 지름 20, 색상(255,0,0)
cy 50,0,20 0,0,1 14.2 21.42 10,0,255  # Cylinder: 중심(50,0,20), 축(0,0,1), 지름 14.2, 높이 21.42, 색상(10,0,255)

4장: 보너스 기능 (선택 사항)
레이 트레이싱 기법을 활용하면 반사, 투명, 굴절, 부드러운 그림자, 전역 조명, 범프 매핑 등 다양한 효과를 구현할 수 있습니다.
그러나 miniRT에서는 기본적인 기능만 구현하는 것이 목표이므로, 보너스는 간단한 추가 기능만 허용됩니다.

보너스 목록
Phong 반사 모델을 통한 스페큘러 반사 추가
체커보드 패턴 적용 (색상 변조)
다중 광원 지원
추가적인 2차 곡선 객체 (예: 원뿔(Cone), 쌍곡면(Hyperboloid), 포물면(Paraboloid))
범프 맵(Bump Mapping) 적용

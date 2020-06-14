# 精緻作業系統（第二版）讀書心得
```
作者：吳婕安 日期：2020/6/24
說明: 本讀書心得的節錄內容主要來源為--精緻作業系統（第二版）
```

## 本書簡介
````
本書作者為賈蓉生、許世豪、林金池、賈敏原，於2012/5/25由博碩出版社出版。
內容針對大專院校作業系統課程教學需求，設計五篇共15章： 
(1)系統架構(System Structure)，電腦系統結構、作業系統架構；
(2)行程管理(Process Management)，行程、執行緒、CPU排程、同步並行、死結； 
(3)儲存管理(Storage Management)，記憶體管理、虛擬記憶體、檔案系統；
(4)輸入輸出(Input and Output)，輸入輸出系統、大量儲存結構； 
(5)分散式系統(Distributed System)，分散式系統結構、分散式系統之整合、雲端概念。
````
## 以下心得以章節作區分:
### CHAPTER 0導讀
#### 心得
````
在看完這一章之後，我了解了作業系統的分類，及其再細分的系統有甚麼差異，
希望在有這些概念之後我能夠更輕易的理解本書後面的內容。
````
#### 重點整理
````
書中描述作業系統是一組系統程式，介於使用者與電腦硬體之間，幫助使用者方便使用並監督電腦有效執行。
一套完整之電腦系統可概分為四組區塊:
(1)電腦硬體(Computer Hardware)
(2)作業系統(Operating System)
(3)應用程式(Application Program)
(4)使用者(Users)
![](0-1圖片網址) 

代表性的作業系統有 : 
1.大型電腦作業系統(Mainframe System):
因應不同的需求可再類分為批次系統(BatchSystems)、即時系統(Real-Time Systems)、
多工系統(Multi-programmedSystems)，與分時系統(Time-Sharing Systems)
![](0-2圖片網址)

2.微型電腦作業系統(Microcomputer System): 
微型電腦分成個人桌上型電腦系統(PC或稱 Desktop)、筆記型電腦系統(Notebook 或稱Laptop)、
手持式電腦系統(Handheld) 等。
![](0-3圖片網址)
3.多處理器作業系統(MultiprocessorSystem): 
	此作業系統的優點有增加效率、節省成本、增加可靠性

多處理器系統可類分為對稱多處理器系統、非對稱多處理器系統:
1.對稱多處理器系統(Symmetric Multiprocessing):
![](0-4圖片網址)
2.非對稱多處理器系統(Asymmetric Multiprocessing): 
![](0-5圖片網址)

4.分散式作業系統(Distributed System): 
應用網路連接讓放置各處的電腦合作執行指定的工作。
分散式系統在功能分配上可分為主從系統、點對點系統:
1. 主從系統(Server--Client System):
![](0-6圖片網址)
2. 點對點系統(Peer to Peer System 或 P2P):
![](0-7圖片網址)
5.雲端作業系統(CloudSystem):
雲端運算將原由本地電腦之運算及儲存的資料，交由雲端網站運算及儲存。
雲端運算的基本特性是“運算在雲端(Computing is in the Cloud)"，需滿足:
1、多個大規模資料中心(Information Centers)與大量處理器(Processers)
2、無憂服務(Non-Worry Service)
````

### CHAPTER 1電腦系統結構
````
````

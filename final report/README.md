# 精緻作業系統（第二版）讀書心得
```
作者：吳婕安 日期：2020/6/24
說明: 本讀書心得的節錄內容主要來源為--精緻作業系統（第二版）
```

## 本書簡介

本書作者為賈蓉生、許世豪、林金池、賈敏原，於2012/5/25由博碩出版社出版。
內容針對大專院校作業系統課程教學需求，設計五篇共15章： 
(1)系統架構(System Structure)，電腦系統結構、作業系統架構；  
(2)行程管理(Process Management)，行程、執行緒、CPU排程、同步並行、死結；   
(3)儲存管理(Storage Management)，記憶體管理、虛擬記憶體、檔案系統；  
(4)輸入輸出(Input and Output)，輸入輸出系統、大量儲存結構；   
(5)分散式系統(Distributed System)，分散式系統結構、分散式系統之整合、雲端概念。  

## 以下心得以章節作區分:
### CHAPTER 0導讀
#### 心得

在看完這一章之後，我了解了作業系統的分類，及其再細分的系統有甚麼差異，
希望在有這些概念之後我能夠更輕易的理解本書後面的內容。

#### 重點整理

作業系統是一組系統程式，介於使用者與電腦硬體之間，幫助使用者方便使用並監督電腦有效執行。
一套完整之電腦系統可概分為四組區塊:
(1)電腦硬體(Computer Hardware)
(2)作業系統(Operating System)
(3)應用程式(Application Program)
(4)使用者(Users)
![](https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/0-1.jpg) 

代表性的作業系統有 : 
1.大型電腦作業系統(Mainframe System):
因應不同的需求可再類分為批次系統(Batch Systems)、即時系統(Real-Time Systems) 、多工系統(Multi-programmed Systems)，與分時系統(Time-Sharing Systems)

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/0-2.jpg)

2.微型電腦作業系統(Microcomputer System): 
微型電腦分成個人桌上型電腦系統(PC或稱 Desktop)、筆記型電腦系統(Notebook 或稱Laptop) 、手持式電腦系統(Handheld) 等。

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/0-3.jpg)

3.多處理器作業系統(Multiprocessor System): 
	此作業系統的優點有增加效率、節省成本、增加可靠性

多處理器系統可類分為對稱多處理器系統、非對稱多處理器系統:
1.對稱多處理器系統(Symmetric Multiprocessing):

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/0-4.jpg)

2.非對稱多處理器系統(Asymmetric Multiprocessing): 

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/0-5.jpg)

4.分散式作業系統(Distributed System): 
應用網路連接讓放置各處的電腦合作執行指定的工作。
分散式系統在功能分配上可分為主從系統、點對點系統:
(1) 主從系統(Server--Client System):

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/0-6.jpg)

(2) 點對點系統(Peer to Peer System 或 P2P):

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/0-7.jpg)

5.雲端作業系統(Cloud System):
雲端運算將原由本地電腦之運算及儲存的資料，交由雲端網站運算及儲存。
雲端運算的基本特性是“運算在雲端(Computing is in the Cloud)"，需滿足:
(1)多個大規模資料中心(Information Centers)與大量處理器(Processers)
(2)無憂服務(Non-Worry Service)


### CHAPTER 1電腦系統結構
#### 心得

這一章對電腦的基本系統架構進行了介紹，讓我對電腦系統結構、計算機結構與作業系統間之互動架構有了一些基礎的概念，希望在經過這一章的解說讓我能夠較容易地去理解幣二章的東西。

#### 重點整理

此章節內容包括起始操作、中斷、輸入輸出架構、儲存架構、硬體保護及網路架構。
最新型電腦系統(Modern Computer System) 之架構

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/1-1.jpg)

1.起始操作(Start Running):
開啟電腦時即啟動初始程式(Initial Program或Bootstrap Program)，此程式置於唯讀記憶體(ROM)，初始啟動CPU、装置控制器、傳導器與記憶體；初始程式將作業系統載入記憶體作核心運行。
核心運行(Kernel)從開機到關機一直都保持運作，等待從硬體、軟體傳來事件信號，執行事件要求的工作,並進行監督。

2.中斷(Interrupt)
中斷驅動系統(Interrupt Driven)，當傳來優先事件信號時，CPU回應作業系統要求，立即停止正在執行的工作，轉向執行優先事件，待事件執行完畢後,再繼續執行原來未完成之工作。
新型電腦均採用堆疊(Stack)方法，將中斷時每一步驟之位址依序記錄於特定堆疊中，等待中斷事件執行完畢後再由堆疊中取得各位址，反序找到中斷位址繼續執行原來之工作。
將有些經常發生的事件視為可預測的經常異常，在作業系統中將其解決方法以程序儲存於ROM中，另建”中斷異常表”來放置指標，指向唯讀記憶體中對應之中斷方法程序。

3.輸入輸出架構(I/O Structure)
當裝置要求執行資料輸入輸出(I/O)時，CPU載入該裝置控制器內暫存器之功能程序，由作業系統導引中斷，執行資料的輸入輸出。

當CPU執行輸入輸出時，因CPU的動作快，I/O設備的動作慢，因此無法同步執行使I/O之中斷與其他程序之中斷略為不同。

I/O中斷可分為同步I/O(Synchronous)與非同步I/O(Asynchronous):

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/1-2.jpg)

平常I/O事件由CPU主導執行，如果CPU很忙碌，或是該 I/O事件的優先等級較低，而無法由CPU作立即地執行，作業系統可以“記憶體直接存取方法(Direct Memory Access 或 DMA)"直接將I/O事件對記憶體執行存取。
但記億體直接存取方法(DMA)仍有其使用條件:
(1)	I/O裝置為高速且傳輸量大的裝置。
(如果量小速低，偷取少許CPU記憶體，經由CPU主導執行即可)
(2)	確定傳輸的資料無異常。
(一般CPU有篩檢資料異常的功能來確保資料安全，如果不經過CPU篩檢直接對記憶體作存取，則須確定傳輸的資料無異常)

4.儲存架構(Storage Structure)
CPU直接對主記憶體(Main Memory)隨機存取資料，
典型的指令執行週期，如馮紐曼提出的執行架構:

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/1-3.jpg)
![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/1-4.jpg)


5.硬體保護(Hardware Protection)
現今電腦性能均為多人多工(Multi-Users/Multi-Jobs): 
(1)多個使用者藉由網路連線一台電腦作執行
(2)於同一電腦内，多個工作籍由分時方法同時於 CPU執行
因此難免會發生人為程式的錯誤,而傷害到電腦硬體系統·

一台電腦硬體受傷害多是因為人為程式的錯，因此電腦硬體保護就是摒除人為程式的錯誤，而保護的對象為:(1)I/O系統、(2)記憶體、(3)中央處理器(CPU)ㆍ

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/1-5.jpg)

一般新型電腦採用“雙模操作法(Dual-ModeOperation)”來摒除人為程式對硬體的傷害。
雙模是指使用者模式與系統模式(或稱監視模式、優先執行模式)在執行過程中，遇到可能傷及硬體的操作，立即由使用者模式轉交系統模式執行，等該危險操作執行完畢後，再交還使用者模式繼績正常操作。

6網路架構(Network Structure)
常見的網路架構有小範圍區域網路及大範圍廣域網路

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/1-6.jpg)



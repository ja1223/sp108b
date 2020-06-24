# 精緻作業系統（第二版）讀書筆記
```
作者：吳婕安 日期：2020/6/24
說明: 本筆記的節錄內容主要來源為--精緻作業系統（第二版）
筆記中的表格內容皆是從書中節錄並自行整理的。
筆記中的圖片幾乎都是從書中擷取的，若是自行繪圖或有修改會特別註明。

```

## 本書簡介

本書作者為賈蓉生、許世豪、林金池、賈敏原，於2012/5/25由博碩出版社出版。<br>
內容針對大專院校作業系統課程教學需求，設計五篇共15章：<br>
(1)系統架構(System Structure)，電腦系統結構、作業系統架構；<br>
(2)行程管理(Process Management)，行程、執行緒、CPU排程、同步並行、死結；<br>
(3)儲存管理(Storage Management)，記憶體管理、虛擬記憶體、檔案系統；<br>
(4)輸入輸出(Input and Output)，輸入輸出系統、大量儲存結構；<br>
(5)分散式系統(Distributed System)，分散式系統結構、分散式系統之整合、雲端概念。<br>

## 讀書筆記
### CHAPTER 0 導讀
作業系統是一組系統程式，介於使用者與電腦硬體之間，幫助使用者方便使用並監督電腦有效執行。
一套完整之電腦系統可概分為四組區塊:
(1)電腦硬體(Computer Hardware)<br>
(2)作業系統(Operating System)<br>
(3)應用程式(Application Program)<br>
(4)使用者(Users)<br>
![](https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/0-1.jpg) <br>

代表性的作業系統有 :<br>
1.大型電腦作業系統(Mainframe System):<br>
因應不同的需求可再類分為批次系統(Batch Systems)、即時系統(Real-Time Systems) 、多工系統(Multi-programmed Systems)，與分時系統(Time-Sharing Systems)

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/0-2.jpg) <br>

2.微型電腦作業系統(Microcomputer System): <br>
微型電腦分成個人桌上型電腦系統(PC或稱 Desktop)、筆記型電腦系統(Notebook 或稱Laptop) 、手持式電腦系統(Handheld) 等。

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/0-3.jpg) <br>

3.多處理器作業系統(Multiprocessor System): <br>
此作業系統的優點有增加效率、節省成本、增加可靠性<br>

多處理器系統可類分為對稱多處理器系統、非對稱多處理器系統:<br>
1.對稱多處理器系統(Symmetric Multiprocessing):

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/0-4.jpg) <br>

2.非對稱多處理器系統(Asymmetric Multiprocessing): 

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/0-5.jpg) <br>

4.分散式作業系統(Distributed System): <br>
應用網路連接讓放置各處的電腦合作執行指定的工作。<br>
分散式系統在功能分配上可分為主從系統、點對點系統:<br>
(1) 主從系統(Server--Client System):

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/0-6.jpg) <br>

(2) 點對點系統(Peer to Peer System 或 P2P):

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/0-7.jpg) <br>

5.雲端作業系統(Cloud System):<br>
雲端運算將原由本地電腦之運算及儲存的資料，交由雲端網站運算及儲存。<br>
雲端運算的基本特性是“運算在雲端(Computing is in the Cloud)"，需滿足:<br>
(1)多個大規模資料中心(Information Centers)與大量處理器(Processers)<br>
(2)無憂服務(Non-Worry Service)<br>


### CHAPTER 1 電腦系統結構
此章節內容包括起始操作、中斷、輸入輸出架構、儲存架構、硬體保護及網路架構。<br>
最新型電腦系統(Modern Computer System) 之架構<br>

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/1-1.jpg) <br>

1.起始操作(Start Running)<br>
開啟電腦時即啟動初始程式(Initial Program或Bootstrap Program)，此程式置於唯讀記憶體(ROM)，初始啟動CPU、装置控制器、傳導器與記憶體；初始程式將作業系統載入記憶體作核心運行。
核心運行(Kernel)從開機到關機一直都保持運作，等待從硬體、軟體傳來事件信號，執行事件要求的工作,並進行監督。

2.中斷(Interrupt)<br>
中斷驅動系統(Interrupt Driven)，當傳來優先事件信號時，CPU回應作業系統要求，立即停止正在執行的工作，轉向執行優先事件，待事件執行完畢後,再繼續執行原來未完成之工作。
新型電腦均採用堆疊(Stack)方法，將中斷時每一步驟之位址依序記錄於特定堆疊中，等待中斷事件執行完畢後再由堆疊中取得各位址，反序找到中斷位址繼續執行原來之工作。
將有些經常發生的事件視為可預測的經常異常，在作業系統中將其解決方法以程序儲存於ROM中，另建”中斷異常表”來放置指標，指向唯讀記憶體中對應之中斷方法程序。

3.輸入輸出架構(I/O Structure)<br>
當裝置要求執行資料輸入輸出(I/O)時，CPU載入該裝置控制器內暫存器之功能程序，由作業系統導引中斷，執行資料的輸入輸出。<br>

當CPU執行輸入輸出時，因CPU的動作快，I/O設備的動作慢，因此無法同步執行使I/O之中斷與其他程序之中斷略為不同。<br>

I/O中斷可分為同步I/O(Synchronous)與非同步I/O(Asynchronous):

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/1-2.jpg) <br>

平常I/O事件由CPU主導執行，如果CPU很忙碌，或是該 I/O事件的優先等級較低，而無法由CPU作立即地執行，作業系統可以“記憶體直接存取方法(Direct Memory Access 或 DMA)"直接將I/O事件對記憶體執行存取。<br>
但記憶體直接存取方法(DMA)仍有其使用條件:<br>
(1)I/O裝置為高速且傳輸量大的裝置。
(如果量小速低，偷取少許CPU記憶體，經由CPU主導執行即可)<br>
(2)確定傳輸的資料無異常。
(一般CPU有篩檢資料異常的功能來確保資料安全，如果不經過CPU篩檢直接對記憶體作存取，則須確定傳輸的資料無異常)<br>

4.儲存架構(Storage Structure)<br>
CPU直接對主記憶體(Main Memory)隨機存取資料，<br>
典型的指令執行週期，如馮紐曼提出的執行架構:<br>

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/1-3.jpg) <br>
上圖擷取了書中的圖1-5-1並增加自己的整理(虛線框中的文字) <br>
![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/1-4.jpg) <br>


5.硬體保護(Hardware Protection)<br>
現今電腦性能均為多人多工(Multi-Users/Multi-Jobs): <br>
(1)多個使用者藉由網路連線一台電腦作執行<br>
(2)於同一電腦内，多個工作籍由分時方法同時於 CPU執行<br>
因此難免會發生人為程式的錯誤,而傷害到電腦硬體系統<br>

一台電腦硬體受傷害多是因為人為程式的錯，因此電腦硬體保護就是摒除人為程式的錯誤，而保護的對象為:(1)I/O系統、(2)記憶體、(3)中央處理器(CPU)ㆍ

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/1-5.jpg) <br>

一般新型電腦採用“雙模操作法(Dual-Mode Operation)”來摒除人為程式對硬體的傷害。<br>
雙模是指使用者模式與系統模式(或稱監視模式、優先執行模式)在執行過程中，遇到可能傷及硬體的操作，立即由使用者模式轉交系統模式執行，等該危險操作執行完畢後，再交還使用者模式繼績正常操作。<br>

6.網路架構(Network Structure)<br>
常見的網路架構有小範圍區域網路及大範圍廣域網路

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/1-6.jpg) <br>

### CHAPTER 2 作業系統架構
1.系統組成要件(System Components) <br>
作業系統可以就功能性分成行程管理、主記憶體管理、檔案管理、輸入輸出管理、輔助記憶體、網路連通管理、保護管理、指令解釋管理。<br>

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/2-1.jpg) <br>

2. 作業系統服務(Operating System Services) <br>

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/2-2.jpg) <br>

3.系統呼叫(System Calls) <br>
當行程要求系統呼應執行某項工作就稱為系統呼叫，除了低階語言(如組合語言)與少數高階語言外，為了保護系統安全，一般高階語言必須間接作系統呼叫，亦即是在系統監視下由系統導引執行。<br>
(1)系統呼叫與參數傳遞(System Call and Parameter) <br>

![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/2-3.jpg) <br>

(2)系統呼叫時機(Timing for System Call) <br>
系統呼叫可用於行程控制、檔案操作、裝置操作、資料維護、連線通訊
![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/2-4.jpg) <br>

4. 系統程式(System Programs) <br>
系統程式提供使用者程式ㅡ個環境(使用者與系統程式間的介面)，可藉系統呼叫或其他方式執行，一般可類分為: <br>

(1)檔案管理(File Management)系統程式:對檔案或目錄執行建立、刪除、複製、重新命名。<br>
(2)狀況資訊(Status Information)系統程式:提供時間、日期、可用之記憶體空間、使用者人數等系統資料。<br>
(3)檔案修改(File Modification)系統程式:可更新輔助記憶體如磁碟、磁帶之檔案內容。<br>
(4)支援電腦語言之程式設計(Language Programming Support) 系統程式:以編譯程式、直譯程式、組合語言等，引導一般高階語言轉換成可執行的目的機器碼。<br>
(5)語言程式之載入與執行(Program Loading and Execution) 系統程式:一旦語言程式轉換成目的機器碼，即載入主記憶體進入CPU被執行。<br>
(6)通訊(Communication)系統程式:這類系統程式在行程、使用者、電腦系統間，建立連通管道，使之相互傳遞訊息、相互支援。<br>

5.應用程式 (Application Programs) <br>
應用程式用來支援解決一般之應用問題，這些程式包括網路瀏覧器、文字處理器、試算表、資料庫、繪圖、統計分析、遊戲等。<br>

6.系統架構(System Structure) <br>
隨著電腦應用需求之增加，其結構概念也由整體架構改向為小單位分割架構 <br>
![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/2-5.jpg)<br>
系統架構可累分為簡易架構、階層架構、微核心、模組架構。<br>
![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/2-6.jpg) <br>
![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/2-7.jpg) <br>
上圖擷取了書中的圖2-7-5並增加自己的整理(框框中的文字) <br>
<br>

7.虛擬機器(Virtual Machines) <br>
虛擬機器，IBM首先發展完成，雖仍有些許缺點但有更多的優點，<br>
其可分為幾個區塊: <br>
![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/2-8.jpg) <br>
上圖擷取了書中的圖2-8-2並增加自己的整理(框框中的文字) <br>
8.系統設計與編寫(System Design and Implementation) <br>
設計觀點從使用者與系統的角度來探討，使用者要求的是方便使用、容易學習、高可信度、安全迅速；系統要求的是容易設計、容易建立、容易維護、容易操作。<br>
關鍵機制(Mechanisms)通常以低階語言(組合語言)編寫,也有小部份以高階語言(C、C++)編寫，新型作業系就以Java 編寫。<br>
![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/2-9.jpg) <br>

10.檢選系統(System Generation) <br>
系統程式之設計考量是適用於同型電腦、適用於不同的場所、適用於不同的環境。,
為了滿足不同場所與周遭環境，須考量所有可能的狀況，於使用時再選有用的内容納入作業系統，如此設計的作業系統稱為“檢選系統(SYSGEN)" 。<br>
SYSGEN存於碘碟、光碟内，開機後開機程式讀取電腦的環境需求，再從SYSGEN讀取適當內容組成該機的作業系統，其中必須要決定的資料有: <br>
(1) CPU屬性(如果有多個CPU，每一個的屬性都需讀取) <br>
(2)記憶體的容量需求<br>
(3)本機與周邊之配置装置<br>
(4)最佳化系統選項<br>

11.開機系統(System Boot) <br>
當電腦開啟電源或重新啟動時，將指令暫存器(IR)載入，同時執行開機程式。開機程式儲存於ROM内，不須任何初始動作開機就執行，亦不受任何病毒的入侵。<br>
開機程式執行:首先出現對話視窗供使用者勾選需求，然後進入開機步驟，初始所有系統要件，從CPU、暫存器、裝置控制器，到主記億體、作業系統，開啟電腦。<br>

### CHAPTER 3 行程
1.行程觀念(Process Concept) <br>
(1)行程狀態(Process State) <br>
![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/3-1.jpg) <br>
上圖擷取了書中的圖3-2-1並增加自己的整理(框框中的文字) <br>
因為CPU一個時間只能處理一個行程，大多數的行程均處在就緒或等待狀態<br>

(2)行程控制區塊(Process Control Block) <br>
随著行程產生，系統配合該行程分配一小段記憶體記錄資訊。<br>
區塊上的資訊隨著行程的可用性、狀態性等變化而改變，主要內容有 : <br>
![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/3-2.jpg) <br>

(3)執行緒(Threads) <br>
CPU一個時間只能處理一個行程，因此多數行程都是在等待狀態，給某些行程競爭特質，如此具有搶進CPU特性之行程稱為執行緒。<br>
早期系統一個行程僅允許一個執行緒，新型電腦一個行程允許擁有多個執行緒，在一個時間中可執行多個任務工作。<br>

2.排程(Process Scheduling) <br>
(1)排程佇列(Scheduling Queues) <br>
當多個行程在等待時，為了有效執行系統將等待的行程置於一個佇列内，就迫切性再作一次排序，這個佇列稱為”排程佇列(Scheduling Queue)” <br>
行列管理可用在系統內的許多地方，像是:進入CPU前、進入執行I/O前等，將等待執行的行程導入佇列，依優先迫切性排序排程作最有效之執行<br>
(2)排程器(Schedulers) <br>
“排程器(Scheduler)”用來在數個行程中，依優先迫切性排序選出一個最有意義的行程進入執行管道。<br>
排程器可分為遠程排程器與近程排程器: <br>
![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/3-3.jpg) <br>
在執行速率上行程可分為慢速之I/O型行程與快速之 CPU型行程: <br>
![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/3-4.jpg) <br>
(3)內文切換(Context Switch) <br>
切換時系統會儲存行程之PCB或載入行程之PCBㆍ但PCB如同一個文字檔的內文資料繁多，因此進行轉換時如同内文切換需付出很大的資源代價。<br>
解決的方法是: <br>
a.導入以執行緒作業,使其自行競爭搶入,增快執行速度。 <br>
b.盡可能不作切換的動作,以節省資源代價。<br>
3.行程操作(Operations on Processes) <br>
(1)行程產生(Process Creation) <br>
一個行程可藉”建立新行程系統呼叫”建立另一個新的子行程，原行程稱“父行程"，新產生的行程稱“子行程。<br>
![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/3-5.jpg) <br>
上圖是參考書中的圖3-4-1畫的 <br>
行程須搭配資源才可執行，其中資源如CPU時間、記憶體、檔案、I/O裝置等，這些資源可能來自系統或父行程的分配。資源管理是一種管制機制，沒有足夠的資源就不能無意義地建立新行程。<br>
除此之外,父行程與子行程之關係尚有: <br>
a.在初始特性上:父行程原有的初始値，可隨著建立新行程將其傳遞給子行程。<br>
b.在執行時機上:(a)父行程與子行程同時在系統中作執行；(b)父行程在建立子行程時即停止執行，等待各子行程執行結束後，父行程再繼續執行。<br>
c.在行程內容上:(a)子行程完全複製於父行程；(b)子行程除了父行程給予的內容外，另添加自己的程式內容。<br>
(2)行程結束(Process Termination) <br>
當行程完成付予的任務後結束並消失，消失前傅遞結束訊息給其父行程，並將資源繳回系統。<br>
除了因完成任務而結束外，行程也有其他原因被迫結束: <br>
a.一個行程可能因某項原因，以系統呼叫結束其他某特定的行程。<br>
b.一個行程可能因要求份外資源，被其父行程或系統結束。<br>
c.若所付予的任務已不再有需要，該行程被其父行程或系統結束。<br>
d.若父行程已結束，子行程亦隨之結束，此現象稱為“連動結束" 。<br>
4.合作行程(Cooperating Processes) <br>
一個行程如果不影響其他行程、不被其他行程影響、亦不與其他行程共享資料或資源稱為“獨立行程"；否則稱為“合作行程"<br>
行程應合作的理由有: (1)資料分享(Information Sharing) ；(2)增進執行速率(Computation Speedup)； (3)模組應用(Modularity)； (4)方便使用(Convenience)。<br>
5.行程通訊(Interprocess Communication或 IPC) <br>
行程通訊是指兩個行程互通訊息，這兩個行程可能編譯自同一程式或不同的多個程式。<br>
(1)訊息傳遞(Message Passing System)
兩個行程相互通訊必須先建立連通途徑，一個行程執行傅送，另一個行程執行接收。<br>
通訊途徑可類分為直接通訊與間接通訊。 <br>
![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/3-6.jpg) <br>
(2)同步操作(Synchronization) <br>
行程間之訊息傳遞依賴呼叫方法程序send()與receive()而得以執行。<br>
資料以兩種方式傳送: <br>
![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/3-7.jpg) <br>
(3)緩衝操作(Buffering) <br>
於兩行程間設立緩衝器，在資料送建之前以佇列方式在緩衝器內先作暫時駐留。<br>
佇列以3種容量方式暫存資料: <br>
![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/3-8.jpg) <br>
6.網路連通(Server/Client Network) <br>
網路連通之要件為網址(IP)、埠(Port)與平台(Socket)，網址用於尋找網路節點，埠用於匹配功能區段，平台用於連接通道。<br>
### CHAPTER 4 執行緒
1.簡介<br>
被付給行程競爭特質、會競爭搶入CPU被執行的行程，稱為“執行緒(Thread)"。<br>
早期一個行程僅允許一個執行緒，新型電腦一個行程允許多個執行緒，利用CPU分時執行方法可在一個時間執行多個工作。<br>
2.執行緒定義(Overview) <br>
每個執行緒擁有各自的識别碼(ID)、指令計數器、暫存器組、一個堆疊。<br>
同屬一個行程的執行緒可共享程式碼、資料、檔案等系統資源。<br>
一個多元性工作的行程可依工作內容分割出多個執行緒，其優點有: <br>
(1)工作分擔(Responsiveness):依工作內容分割出多個執行緒，一個出問題亦不影響其他執行緒的執行。<br>
(2)資源分享(Resource Sharing): 數個執行緒可共享其所屬行程之各項資源，以節省系統之整體資源。<br>
(3)資源節省(Economy):只要有機會，執行緒立即競爭推入CPU執行，自動節省CPU時間與其他資源的代價。<br>
(4)適用於多行程架構(Utilization of Multiprocessor Architecture):原本為多行程設計的架構，一樣可用於多執行緒之執行，不必另付修改代價。<br>
執行緒發生在使用者階層者稱為“使用者執行緒”，由核心支援，由使用者管理；發生在核心階層者稱為“核心執行緒”，由核心支援、管理。<br>
執行緒庫可提供程式一個API，以此API產生並管理執行緒。<br>
使用執行緒庫之行徑有: <br>
(1)在使用者階層內，因為庫中已存有可使用的執行緒，所以使用者可直接從庫中
抓取使用。<br>
(2)在核心階層內，除了庫中已存有可使用的執行緒外,可視需要直接要求核心增添執行緒到庫中提供使用。<br>
3.多執行緒模型(Multithreading Models) <br>
![]( https://github.com/ja1223/sp108b/blob/master/final%20report/pictures/4-1.jpg) <br>
4.執行緒操作(Operations of Threads) <br>
(1)執行緒之終止(Cancellation)
一個行程有多個所屬之執行緒，其中“終止”的執行緒稱為“標的執行緒(Target Thread)"。<br>
當標的執行緒執行“終止”時，因系統的不同分為兩種情況: <br>
a.非同步終止(Asynchronous Cancellation):接獲終止信號時，標的執行緒立即執行終止作為，無需考量其他執行緒的狀況。<br>
b.延展終止(Deferred Cancellation):接獲終止信號時，分期察看其他執行緒之狀況，並於最佳時機(終止點(Cancellation Point))執行終止作為。<br>
(2)執行緒之信號管理(Signal Handling) <br>
在多個行程與執行緒環境中，各執行緒可以信號傳遞執行要求。<br>
無論是同步傳遞或是非同步傳遞，所有的信號均以下列方式進行: <br>
a.信號是由某特定事件的要求而產生; <br>
b.信號傳遞予行程或執行緒; <br>
c.信號一旦被發送必須處於監控管理下。<br>

使用者定義信號優先於核心即定信號。<br>
信號傳遞與收發行程或執行緒間的關係有: <br>
a.將信號傳遞給予有要求使用的執行緒; <br>
b.信號傳遞給予屬於同一行程之每一執行緒; <br>
c.將信號傳遞給予行程之某些執行緒; <br>
d.指定一個執行緒，為其所屬之行程接收所有傳遞至該行程之信號。<br>
(3)執行緒池(Thread Pools) <br>
為了解決”無節制地產生執行緒”系統設置執行緒池容納一定數量的執行緒，當任務需要某種執行緒時，先到執行緒池搜尋適用的即存執行緒，如果搜尋不到再視執行緒池內執行緒的數量，產生所需要的新執行緒或執行等待。<br>
等待時可能有2種狀況發生: <br>
(1)等待池内有執行縮因不再需要而消失，再產生所需的新執行緒。<br>
(2)等待從任務返回的執行緒，如果適用，立即抓取使用。<br>
執行緒池有下列優點: <br>
(1)使用池内即存的適用執行緒比產生新執行緒要付出較少的代價。<br>
(2)保持一定數量的執行緒使系統不致混亂。<br>

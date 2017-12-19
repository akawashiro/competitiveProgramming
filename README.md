# 落ちたら危険！NP困難問題
## クリーク問題
グラフGにサイズkのクリークが存在しますか?
サイズkのクリーク:互いに隣接しているk個の頂点
## 頂点被覆問題
グラフGにサイズkの頂点被覆が存在しますか?
サイズkの頂点被覆:k個の頂点の集合Sであって、Gのすべての辺について少なくとも一方の端点がSに含まれるようなもの
## 有向/無向閉路除去問題
有向/無向グラフGからk本の辺を除去して閉路をすべて無くせるか
## 有向/無向ハミルトン閉路問題
有向/無向グラフGにハミルトン閉路が存在するか?
## 強連結部分グラフ問題
Gの辺をk本だけ残した部分グラフで強連結なものは存在するか?
# 落ちたら勝利！P問題
## 有向/無向オイラー回路問題
一筆書き問題。
有向なら各頂点に対して(出次数) = (入次数) && 孤立点を除いて連結
無向なら各頂点に対して次数が偶数 && 孤立点を除いて連結
## 頂点彩色問題
無向グラフGの頂点をk色で彩色できるか
## "集合分割問題"
[入力] 有限集合 U の部分集合 S1, ..., Sr  
[出力] Si のうちいくつかで U 全体をちょうど覆うことはできるか？
## 2SAT
強連結成分分解に落ちる
## Post の対応問題(決定不能)
[入力] 0/1 の列たち a1, ..., ar, b1, ..., br  
[出力] ai1ai2...aik = bi1bi2...bik となるような i1,i2, ..., ik (k > 0) は存在するか？ (ij は同じ値を複数回含んでもよい)  
# 過去問の復習 
## [C - ウサギ跳び](https://beta.atcoder.jp/contests/arc041/tasks/arc041_c)　パズルゲー
### Caution! パズルゲーです
背中合わせのうさぎは互いに影響しない。  
よってRRR....LL/RR..LL/R.....LLLのように分割したうえで各ブロックについてR/Lのうち多い方をジャンプさせれば良い。
## [C - データ構造](https://arc033.contest.atcoder.jp/tasks/arc033_3) Segment Treeを用いた二分探索
### Segment Tree
Xの範囲がそれほど大きくないので全部の数を0/1で表してSegment Treeに入れる。  
追加のクエリが来たら、Xに1を足す。  
削除のクエリが来たら二部探索でX番目に小さいものを求める。  
[0,r]の和を高速で求められるのでX=sum([0,r])となるrのうち最も大きいrを求める。  
Xの範囲が大きい場合は座標圧縮が必要。
### 二分木
部分木のサイズを持つ平衡二分木でも良さそう。
## [B - 駐車場](https://beta.atcoder.jp/contests/arc056/tasks/arc056_b) 操作を逆順で考える
### UnionFind
操作を逆順で考えるとk番目の人が駐車するとき1~k-1は埋まっている。  
よってk番目の人が駐車するときに使える辺はx-y(k<=x,k<=y)のものだけ。  
これを用いてUnionFindで判定する。
### ダイクストラ
パスのコストを通った頂点のうち最も大きい頂点の番号と定義する。  
このとき頂点iに来れるかどうかはi<=cost(S-i)で判定できる。  
各頂点へのコストはダイクストラで求められる。
## [D - FT Robot](https://beta.atcoder.jp/contests/arc087/tasks/arc087_b) x軸とy軸を分けて考える
x軸方向の移動とy_軸方向の移動に分けることができる。  
各軸についてナップサック問題を解くと到達できるかどうか判定できる。  
直前に回転が無い最初の前進だけは方向が選べないので注意。
## [D - No Need](https://beta.atcoder.jp/contests/abc056/tasks/arc070_b) 単調性を生かして二部探索&内部でDPする二分探索
まずa\_i\<a\_jのとき、aiが必要ならばa\_jも必要である。つまり単調性が成り立つ。  
この性質を用いると二分探索ができる。a\_iが必要かどうかは和がSであって、K<=a\_i+S\<K+a\_iとなる部分集合が存在するかどうかを判定すればよい。  
これはナップサック問題である。  
一回のナップサック問題を解くのにO(N\*K)かかるので全体としてO(log N\*N\*K)かかる。
## [C - だれじゃ](https://beta.atcoder.jp/contests/arc024/tasks/arc024_3) ヒストグラム
n - k + 1通りの始点に対してヒストグラムを求める。(ヒストグラム, 始点位置)の要素からなる配列を用意してソート。同じヒストグラムを持つものの中で始点が最小のものと最大のものを求めて、その差がk以上であるようなものがあれば答えはyesになる。  
## [E - Don't Be a Subsequence](https://beta.atcoder.jp/contests/arc081/tasks/arc081_c) 文字列の構成
まずaからzが少なくとも一回ずつ現れている文字列a\~zがあると、対応する答えは2文字になる。a\~z++a\~zで表される文字列があると対応する答えは3文字になる。任意の文字列について頭からa\~zがいくつ含まれているかを数えれば、答えの文字数がわかる。  
Aの任意のsuffixについて答えの文字数を計算しておく。こうすると答えの文字を先頭からgreedyに決めていくことができる。  
例えば先頭にaを持ってきたとする。A[0:]に対応する答えの長さをKとする。このときA[1:]のなかで最も小さいA[i]='a'となるiを求める。このiは事前に'a'の出現するindexを記録しておくことで高速に求められる。A[i:]に対応する答えの長さがK-1ならばOK、そうでなければ先頭に'a'を持ってくることはできない。  
はじめに答えの長さを求め、その長さになるように答えを構成するのがミソである。
## [E - 高橋君とホテル / Tak and Hotels](https://arc060.contest.atcoder.jp/tasks/arc060_c)　ダブリング
r[i][k]=i番目のホテルから2^k日で到達できる最も右のホテルの番号  
この配列はダブリングのテクニックで求められる。この配列を使えば各クエリを二分探索できる。  

## [D - Stamp Rally](https://agc002.contest.atcoder.jp/tasks/agc002_d) 並列二分探索
辺を増やしながら見ていくと、x[i],y[i]との連結成分の個数が初めてz[i]を超える時刻を求める問題だとわかる。  
クエリが１つの場合は辺を増やすたびにチェックすれば良いのだが、この問題でそれをやるとO(M\*Q)となり間に合わない。  
そこで並列二分探索と呼ばれるテクニックを使う。  
各クエリについていつチェックするかという情報を持つ。  
そしてチェックはその時刻の時にだけ行う。  
チェックする時刻を範囲で持っておいて二分探索する。  
つまり辺を１つずつ増やしてグラフを構成する操作をlogM回繰り返す。  
こうすると全体の計算量がO(max(M,Q)\*logQ)となり間にあう。
## [D - すぬけそだて――トレーニング――](https://colopl2018-qual.contest.atcoder.jp/tasks/colopl2018_qual_d) 二分探索
まずスタミナを使うなら全部使ったほうがいいことがわかる。  
また時刻T0においてはスタミナはXであり、それ以上増えないのでT0でとりあえず一回起動してスタミナを使いきったほうがいいことがわかる。  
DP[i][j]=時刻TiからTNまでにj個のゲームを起動して得られる知能の最大値とすると  
DP[i][j]から次にゲームを起動するTkが最大N通り存在するのでO(N^3)のDPになる。  
これでは間に合わない。  
このDPを高速化することを考える。  
冒頭の２つの考察からゲームを起動スべきタイミングはスタミナができるだけXに近い時だとわかる。(証明はわからない)。  
よってTkの候補は2つしかない。  
スタミナは単調増加するので二分探索が使えてTkの候補はlogNで列挙できる。  
以上からO(N^2\*logN)でDPできる。  
愚直に配列を取るとlong longを5000^2個取るのでメモリを使いまわして節約する必要がある。
## [H - 穴あきケーキ](https://code-thanks-festival-2015-open.contest.atcoder.jp/tasks/code_thanks_festival_2015_h) 二分探索 or 尺取り法
まずある点(x,y)が与えられた時にそれより左上のカロリーの合計を計算しておく。  
こうすることでimos法を使って(x,y),(z,w)で囲まれた長方形のカロリーがO(1)でもとまる。  
カロリー1の物の数、カロリー2の物の数...を同様に記録すれば、  
ある長方形を定めた時の条件を満たす穴あきドーナツの数をO(1)で求めることができる。  
しかし、これではO(R^2\*C^2)となり間に合わない。  

ここで三辺(x,y,z)を決めた時にwの取りうる範囲は精々10個しかないことに注目する。  
wを増やすとカロリーも増えるので単調性が成り立ち、二分探索ができる。
よってO(R^2\*C\*log C)で計算できる。  

x,yを固定した時にzを一増やすと対応するwは必ず増えるのでカロリーの和がK + 1より小さい場合はzを増やし、K + 1以上K + 9以下であれば繰り抜くことのできる穴の個数を計算する。カロリーの和がK + 9より大きくなればwを１つ増やして同じことを繰り返す。
## [C - 高橋君、24歳](https://beta.atcoder.jp/contests/arc009/tasks/arc009_3) 巡回置換 and DP
まずN-K人を選ぶ。これは組み合わせである。  
このあとK人がみんな異なる手紙を受け取る組み合わせを考える。  
DP[i]をi人がみんな異なる手紙を受け取る組み合わせとする。  
このとき、DP[k+1] = k\*DP[k] + DP[k-1]\*kで表される。  
これは最初の項がK人の巡回置換への挿入であり、  
ふたつ目の項がひとつとってきて2人の巡回置換を作りk-1人のものと組み合わせることを意味する。  

全員異なる組み合わせはいくつかの互いに素な巡回置換の積で表される。  
## [A Single One](https://csacademy.com/contest/archive/task/a-single-one/statement/) set上の二分探索、削除
1が立つのは常に奇数/偶数のインデックスで連続した範囲。  
BFSをしつつ連続したところからインデックスを削除していく。  
setのlower_boundを使えばlog Nで検索できる。  
対象の範囲を削除しながら答えを書き込んでいく。  
set::lower_boundを呼び出さないと遅いので注意。  
se.lower_bound(value)ということ。
## [0-K Multiple](https://csacademy.com/contest/archive/task/0-k-multiple/) 数の構成 and BFS
数を小さい方から構成していくという発想が必要。  
あまりの数は0~N-1しか取らないのでBFSできる。
## [H - Union Sets](https://code-thanks-festival-2017.contest.atcoder.jp/tasks/code_thanks_festival_2017_h) マージテク or LCA or 永続化UnionFind
### マージテクを使った解法
N個の集合それぞれに関係する質問クエリをもたせる。  
UnionFindで併合していく。  
このとき質問クエリを小さい方の集合から大きい方の集合に移す。(マージテク)  
また同時に小さい方の集合に入っているクエリの質問をチェックする。  
ひとつの集合はたかだかlog N回しかマージされないのでオーダーはQ * log Nで抑えられる。
### LCAを使った解法
UnionFindで併合関係を管理しながら森を作成。  
このとき同じ集合を併合する関係を除くと、森になることに注意。  
辺のコストをいつ併合したかとすると、求める答えは２頂点間のパス上のコストの最大値。  
ダブリングを用いたLCAを使うと一クエリあたりlogNで処理できる。  
木を作るときに横着して番号の若い方から大きい方に辺をはればDAGになるかと思った。  
でも1->3<-2のようなケースに対応できない。  
結局無向グラフを作ってDFSしないとだめ。
### 並列二分探索を使う方法
Q個のクエリをいつチェックするかという情報を持つ。  
i個目のクエリをtiにチェックしたとする。  
このとき条件が満たれていればtiより小さい時刻でつながっている。  
逆に大きければtiよりあとの時刻でつながっている。  
この性質を使うといつチェックするかの範囲を持っておくことで二分探索ができる。  
時間計算量はQ*M*log tになる。  
いつチェックするかを時刻からクエリ番号のmapで持つことで一回あたりの計算量がならしでQになる。  
### 永続化配列を用いたUnionFindを使う二分探索
時刻を指定した時にその時刻の配列を復元できるような機能をもたせる。  
こうすると任意の時刻のUnionFindを復元できるので、各クエリについて二分探索ができるようになる。
## [D - Zabuton](https://cf17-final.contest.atcoder.jp/tasks/cf17_final_d) DPのための順序
制約からDPっぽいので良い順序を定めて入力を並び替える必要がありそう。  
今回はH+Pで並び替えるのが良かった。パラメータの一次式を全部試したりするのも良いかも。
## [E - MUL](https://beta.atcoder.jp/contests/arc085/tasks/arc085_c) ProjectSelectionProblem
燃やす埋める問題に帰着できる。  
[最小カットを使って「燃やす埋める問題」を解く](https://www.slideshare.net/shindannin/project-selection-problem)
>N 個の要素がある。最初どの頂点も集合 B に属しているが、これを集合 A に移すことで利益を最大化したい。  
>要素 i が A に属する時には利得 p_i を得るという情報が与えられる。  
>さらに 3 つ組の列 (xj, yj, zj) が与えられ、これは xj が A に属し、かつ yj が B に属していた時に zj(≥ 0) だけ損失をすることを意味する。  
>得られる利得の最大値を答えよ。  
[ProjectSelectionProblem](http://tokoharuland.hateblo.jp/entry/2017/11/12/234636)


## [C - Z塗り](https://arc040.contest.atcoder.jp/tasks/arc040_c)
上の行から見ていって，まだ塗られていない最も右のマスを探し，そこを起点にして塗る．
## [E - 木と整数 / Integers on a Tree](https://arc063.contest.atcoder.jp/tasks/arc063_c)
頂点にかけられている制約はすべて[l,r]={l,l+2,l+4,...,r-2,r}とかける。  
この制約をDFSしながら伝搬していく。  
親の制約が[l,r]であったとき子の制約は[l-1,r+1]になる。  
途中に数字の書かれた頂点があったら区間は[v,v]の形に収束する。  
収束したらDFSの帰りにその制約を伝搬する。  
２つ以上の制約がかち合ったら共通部分を取る。このとき共通部分が空集合なら答えはNoになる。  

何が学べたのかよくわからない。
## [D - Non-decreasing](https://beta.atcoder.jp/contests/arc086/tasks/arc086_b) 発想
### Catution! 発想ゲーです
全部正ならa2+=a1;a3+=a2;...aN+=aN-1;で良い。  
全部負ならaN-1+=aN;aN-2+=aN-1;...;a1+=a2;で良い。  
つまり全部の符号を揃えれば良さそう。これは絶対値の最も大きい物をすべてに足せば良い。  
思いつきはしたが、得られるものは特にない。




## [C - Time Gap](https://cf17-final.contest.atcoder.jp/tasks/cf17_final_c)
24以上は鳩の巣原理から最大値sが0になるので考えなくて良い  
24以下は全探索できる。ただし23の場合だけちょっと工夫してTLEを回避する必要がある。
## [B - GCDロボット](http://ddcc2017-final.contest.atcoder.jp/tasks/ddcc2017_final_b)
いろいろ考えるとgcdのlcmをとる問題になる
## [E - すぬけ君の地下鉄旅行 / Snuke's Subway Trip](http://arc061.contest.atcoder.jp/tasks/arc061_c)
各駅を乗り入れてる路線分だけコピーして改札をでるみたいな頂点を付け加えるとダイクストラできる。
## [B - Contiguous Repainting](http://agc008.contest.atcoder.jp/tasks/agc008_b)
列に対する操作は逆から見ていくといいことが多い
## [D - 切り分けできるかな？](http://arc013.contest.atcoder.jp/tasks/arc013_4)
普通に考えると候補となる分銅の種類x2の鉄塊が必要。  
しかし、ある分銅がX,YにわけられるならXとYはひとつの鉄塊で作れる。  
よってX->Y,Y->Xに辺を貼って二部グラフの最大マッチングを求めると、  
マッチング数分だけ節約できる。
## [E - Grouping](http://arc067.contest.atcoder.jp/)
愚直に考えるとO($N^3$)だが、$\Sigma_{i=1}^N \frac{1}{i} = N log N$なので全体としてO(NlogN)
## [C - 3 Steps](http://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_c)
奇サイクルが存在する = 二部グラフでない
## [C. Points, Lines and Ready-made Titles](http://codeforces.com/contest/871/problem/C)
グリッド系問題における、交点をエッジに変換する発想
## [D - Menagerie](https://arc069.contest.atcoder.jp/submit)
連続する２つがわかれば全部確定する
## [C - 部門分け](http://arc056.contest.atcoder.jp/tasks/arc056_c)
DP[S(=2^Nの部分集合)]=Sを分割して得られる信頼度の最大値、とする。  
このとき各Sについて部分集合Tを列挙する操作を行うとO(2^N\*2^N)になると思いがち。  
しかし実際には2^Nを３つの集合(T,S-T,U-S)に分割しているのでO(3^N)になる。  
方法は↓  
https://kimiyuki.net/blog/2017/07/16/enumerate-sets-with-bit-manipulation/  
DP[S] = max_T ( K - (S-TとTの信頼度の和) + DP[T])  
となる。ここで(S-TとTの信頼度の和)を愚直にO(N^2)で求めると  
全体の計算量がO(N^2*3^N) = O(37,321,507,107) = O(37G)となり多分間に合わない。  

そこでR[S] = Sの中の信頼度の和 を計算しておく。  
すると  
(S-TとTの信頼度の和) = R[S] - R[S-T] - R[T]  
で求められる。  
## [E - Cosmic Rays](http://arc064.contest.atcoder.jp/tasks/arc064_c)
x_s,y_sを0番目のバリア、x_t,y_tをN+1番目のバリアとする。  
このときバリアiとバリアjの間のコストをiからjに直線で動いた時に浴びる宇宙線の量とする。  
このグラフで頂点0から頂点N+1にダイクストラすればよい。  
## [E - Snuke Line](http://arc068.contest.atcoder.jp/tasks/arc068_c)
まずd \in [1,M]とする。  
dを固定するとN種類の名産品をひとつずつ調べることができて  
この操作はM/d*N回かかる。  
今dを1からMまで動かすと\sigma_d=1^M \frac{1}{d}  < log Mなので操作全体はO(M log M * N)かかる。  

ここであるdについて  
[1] d<=(r_i-l_i+1)なら区間iには必ず停車し  
[2] r_i-l_i<=dなら区間iには多くても一回しか停車しないことに着目する。  
よって[2]の場合を考えると  
count[N] という配列を用意してr_i-l_i<=dとなるiについて  
count[j]+=1 (j \in [r_i-l_i])  
としてdずつ動かしてcount[N]の和を取れば良いということである。  

さらに[2]を満たす区間はdについて単調性がある。  
小さなdについて[2]なら大きなdについても[2]である。  
よってdを1からNまで動かしながらcount[N]の[2]を満たす区間に効率よく  
count[j]+=1 (j \in [r_i-l_i])  
できれば良い。これはsegtreeでできる。区間加算、区間和のsegtreeである。  
## [E - Frequency](http://arc069.contest.atcoder.jp/tasks/arc069_c)
{a_i}を高さごとに分類し
{b_{1,i}},{b_{2,i}},...,{b_{m,i}}とする。
ただしb_{1,1} < b_{2,1} < ... < b_{m,1}である。

数列sの最初にはb_{m,1}のインデックスxが入る。
xが何個続くのだろうか。xが続く個数をy個とする。
これはa_iの最大値がb_{m-1,1}になるまでである。
このためにはb_{m,?}の各要素から(b_{m,1}-b_{m-1,1})を引けば良い。よって
y=(b_{m,1}-b_{m-1,1})\*(b_{m,?}の個数) となる。
xがy個続いたあとは数列の最大値はb_{m-1,1}になっている。
つまりb_{m-1,?}の個数がb_{m,?}の個数分だけ増えることになる。
次にアルゴリズムの最初に戻ってやり直せば良い。

このアルゴリズムの実行時間は分類にO(n log n)、数列sの構成にO(n)かかるのでO(n log n)である。

実際に実装するときはb_{i,j}の（値、個数、b_{i,1})のインデックスの組だけを記録すれば良い。
## [E - Meaningful Mean](http://arc075.contest.atcoder.jp/tasks/arc075_c)
まずすべてのiについてa_i-=Kとする。そして累積和s_iを求める。  
このとき[i,j]で条件を満たすのはs_i<=s_jとなるi,jである。  
さらにs_iの値をすべて座標圧縮したものに置き換える。  
座標圧縮によって値の範囲は0~N-1になる。  
座標圧縮してもi,jの条件は変わらない。  
ここで数列を後ろから見ていく。  
[k,i]で条件を満たすiを探すとき、s_{i+1}からs_{N-1}までをsegtreeに入れておく。  
s_xをsegtreeにいれるとはsegtree[s_x]+=1を意味する。  
こうすることで[k,i]の条件を満たすiの個数はsum(s_k,\inf)となる。
segtreeへの挿入&和の操作がlog Nなので全体でO(N log N)で解ける
## [E - Connected?](http://arc076.contest.atcoder.jp/tasks/arc076_c)
たぶん両方共、辺の上にあるやつだけが問題になる。  
辺の上にある数字を全部一直線上に並べる。カッコの対応を取る時のようにStackを使って見ていって全部対応が取れたらOK
## [E - guruguru](http://arc077.contest.atcoder.jp/tasks/arc077_c)
xをm通りすべて試すことを考える。m通り試したあと、愚直にボタンを押す回数を求めるとO(mn)かかってしまう。  
ここで  
x=[a_i+1,a_{i+1}) (a_i<=a_{i+1})  
  =[a_i+1-m,a_{i+1}) (otherwise)  
であれば、a_iからa_{i+1}への照明の切り替えの方法は「お気に入り」からの「順送り」であり
その他の場合は「順送り」のみである  
方法が変化するのはx=a_i+1 or a_i+1-mとなったときなので、これらの数値をmapに入れてO(log n)でチェックできるようにしておく  
「お気に入り」からの「順送り」となる切り替えの個数をX個,「順送り」のみの切り替えの個数をY個とする。  

x=kでのボタンを押す回数をrとする。ここでx=k+1とした時にrr回ボタンを押すとする。  
x=k+1とした時X個のうちXX個が「順送り」になりY個のうちYY個が「お気に入り」からの「順送り」になったとする。  

XX個については直前のx=k+1の時に一回で切り替わっている。  
このためXX個についてrr+=(a_{i+1}-a_i+m)%m-1  
次にYY個についてはボタンを押す回数は変わらない。  
X-XX個はxの値が１増えたのでrr-=(X-XX)とする。  

以上でrが更新できる。XXの和はNなのでこのアルゴリズム全体の計算量はO(m log n)になる  
## [E - Young Maids](http://arc080.contest.atcoder.jp/tasks/arc080_c)
入力例3をよく睨むと列を最後から確定できることがわかる。  
具体的には p1 p2 p3 .... pn としたとき一番最後に取り出されるp_i,p_jは
つぎの条件を満たす。  
p1~p_i-1は取り出されている。つまりi-1は2で割り切れる  
p_i+1~p_j-1は取り出されている。つまりj-i-1は2で割り切れる
よって次のことが言える  
i%2==1,j%2==0 (1-indexedで書いていることに注意)  
以上からi%2==1であり数値が最小のものiとj%2==0でありi<jでありp_jが最小のものをとり出せばよい  

p_iとp_jを取り出した数列に対しても同じことをすれば良いのだが上のアルゴリズムを愚直に実装するとN^2かかる  

ここでp_iとp_jを取り出すと数列はA={p_1~p_i-1}、B={p_i+1~p_j-1}、C={p_j+1~p_n}に分割され
AとBから要素を取ってきたり,AとCから、BとCから取ってくることはない。  
よって問題が分割できる。  
次に取り出すべき要素はAの最小値のうちindexが奇数のもの  
Bの最小値のうちindexが偶数のもの、Cの最小値のうちindexが奇数のものである。  
これはpriority_queueを用いて管理することで適切に取り出せる。  
また最小値を取り出す操作は偶奇を分けたsegtreeをもてば良い。  

青色の部分だが、実装するときには奇数、偶数ではなく  
偶奇が区間の先頭のindexに等しいものとすれば実装が楽。  
## [D - Teleporter](http://agc004.contest.atcoder.jp/tasks/agc004_d)
だいたいの考察があっていた
後で通してどうぞ
## [C - Shorten Diameter](http://agc001.contest.atcoder.jp/tasks/agc001_c)
木には中心という概念が定義できる。  
木の直径をDとすると
- Dが偶数の時、ある頂点vが存在してvから他の頂点への距離がすべてD/2以下になる
- Dが奇数の時、ある辺eが存在してeから他の頂点への距離がすべて(D-1)/2以下になる
この問題では中心を全探索したうえで削除すべき頂点を求めれば良い。
## [C - Knot Puzzle](http://agc002.contest.atcoder.jp/tasks/agc002_c) パズル
a_i + a_{i+1} \>= LであればPossible、そうでなければImpossible
## [サッカー(Soccer)](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0639)
「コスト、ボールの位置」でダイクストラでできる
各マスカラのダイクストラとか思いつかないものが多数
## [Kingdom of JOIOI](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0638)
最小値と最大値に着目したうえで答えを二分探索し
分割を試みる。スライドの分割のところは思いつかなかった。要復習
## [Semiexpress](http://joi2017ho.contest.atcoder.jp/tasks/joi2017ho_b)
DP[i][j]=区間i~i+1にj個準急停車駅をの挿入するときの条件を満たす駅の数
## [Snake JOI](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0635)
拡張ダイクストラ(ノード数=N * 温度 * 3)
## [D - Fennec VS. Snuke](http://arc078.contest.atcoder.jp/tasks/arc078_b)
1からNまでが一本線だと勘違いしてWAした
# これから勉強したいアルゴリズム・定理

## 最大マッチング

## 最小コスト最大マッチング
http://hamayanhamayan.hatenablog.jp/entry/2017/05/09/120253

## ハンガリアン法
人 1 ... n と仕事 1 ... n がある．人 i を仕事 j に割り当てたときの利益が a[i][j] であるとする．このとき，すべての人を，それぞれ異なる仕事につかせることによって，得られる利益を最大化する問題を割り当て問題という．この問題は，二部グラフの最大重みマッチングの特殊な場合であると考えられる．すなわち，二部グラフの両側の頂点数が等しく，完全グラフである場合が割り当て問題である．ハンガリアン法は最小費用流問題に対する主双対法を，行列ベースで書き下したアルゴリズムだと理解することもできる．

## オイラー閉路の存在判定と構成

## 最小有向木
最小全域木の有向グラフ版で、指定された頂点からすべての頂点に到達できるようなもの。

## 最小シュタイナー木
最小全域木の一般化版で指定された頂点を連結にする重み最小の木。

## 関節点・橋
取り除くと連結成分の個数が増加するような頂点・辺のこと。

## 黄金分割法
凸関数の極値を求める手法。

## Suffix Array

## Treap Tree

## Splay Tree

## Link-Cut Tree

## 木の重心分解

## Least Common Ancester

## 2-SAT

## 最小点カバー

## 辺彩色

## Heavy Path Decomposition

## 永続的なデータ構造

# もう知っているアルゴリズム・定理

## 最小カットが最大フローに一致する
### <http://kupc2016.contest.atcoder.jp/tasks/kupc2016_e>
塀を設けるのが辺ではなくグリッドの中央なので、グリッドごとに裏から表に容量1の辺を貼る工夫が必要。

### <http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2251>
二部グラフの最大マッチング問題。ワーシャルフロイドは

REP(k,N)REP(i,N)REP(j,N)
    d[i][j]=min(d[i][k]+d[k][j],d[i][j])

の形で書かないといけない。i,j,kの順番でループを回すとバグる。

## 最小全域木

## 二点間最短経路

## 全点間最短経路

## コストが負の辺を含む時の最短経路

## Segment Tree

## 最小費用流
時間計算量O(F|E|log|V|)

## 強連結成分分解
時間計算量O(|V|+|E|)。アルゴリズム自体はトポロジカルソートしてから逆グラフ?に対してDFSする。つまりDFSx2。
# 間違えた問題
## <http://agc004.contest.atcoder.jp/tasks/agc004_b>
dpテーブルの更新時にメモリをケチって配列一つでうまくやろうとしたらバグった

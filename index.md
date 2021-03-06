# Wrong Answerを出したときにチェックするリスト
- overflow
- modの取り忘れ
- 変数の初期化忘れ(特にデータセットが複数あることに起因するもの)
- 高速化できる箇所の見落とし(各頂点に関する隣接頂点bitmaskの計算)
- メモ化再帰をループに変換するときのカウンタの順序ミス
- 文字列で与えられる頂点情報の数字への変換ミス(文字列で読み込んだものはすべてmapで数字に変換しよう)
- 始点から終点への辺を貼り忘れた
- 辺の追加と追加できるかの判定を同じグラフでやってしまった
- メモ化再帰のキャッシュサイズを間違えた
- 変数の初期化し忘れ
- クエリを後ろから見るときに同一クエリの重複処理をミス。一番最初のクエリを取るべき。
- DPの初期値は必ず0にして良いわけではない
- マージテクでくっ付ける先とくっつける元を逆にしていた
- 自分の知っている典型問題に飛びつきすぎた

# 過去問の復習
## [C - Go Home](https://beta.atcoder.jp/contests/arc070/tasks/arc070_a) 発想
$N\leq \sum_{i=1}^k$となる$k$ならOK.
## [D - Recording](https://beta.atcoder.jp/contests/abc080/tasks/abc080_d)
同じチャンネルの番組はまとめる
## [C - Gr-idian MST](https://beta.atcoder.jp/contests/code-festival-2016-qualb/tasks/codefestival_2016_qualB_c) グリッドの同じ$x$座標/$y$座標をまとめる
最小全域木の構成方法を考えると同じ重みの辺は同時に追加されるので、グリッドの同じ$x$座標/$y$座標をまとめて考えて良い。
## [D - 桁和 / Digit Sum](https://beta.atcoder.jp/contests/abc044/tasks/arc060_b) 入力の平方根に比例する計算時間
$b<\sqrt n$まで全部試したあと、それ以上の$b$については$n$の$b$進数での表現が二桁になることがわかる。あとは上位の桁を決め打ちすれば良い。
- $N=S$のケースは$b=N+1$
- $S=1$のケースは$b=N$

がコーナケースでWAした。 
## [Rabbit Party](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2306) クリークを全列挙
辺の数$M$が100以下なのでクリークの最大サイズは$O(\sqrt{M})$。列挙しても案外大丈夫。
## [Never Wait for Weights](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330) グラフの中に基準点を設ける+マージテク
連結成分の中に基準点を設けて重さをその基準点からの差分で管理する。2つの連結成分が結合するときは小さい方を大きい方にくっつける(マージテク)。
## [D - Patisserie ABC](https://beta.atcoder.jp/contests/abc100/tasks/abc100_d) 絶対値は-1を掛けるか1を掛けるかの場合分け
DPの初期値を0にしてWA。死にたい。
## [Problem F: Marked Ancestor](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2170) クエリを後ろから見る
クエリを後ろから見るとMarkで親とくっつけていく処理に見える。Markが複数あるケースで1WA。
## [C - Interval Game](https://agc025.contest.atcoder.jp/tasks/agc025_c)
左端が最も右→右端が最も左→左端が最も右→ or 右端が最も左→左端が最も右→右端が最も左→
## [D - Static Sushi](https://beta.atcoder.jp/contests/abc095/tasks/arc096_b)
端を決めてもうひとつの端をpriority_queueで決める
## [B - Holes](https://beta.atcoder.jp/contests/agc021/tasks/agc021_b) 無限遠が考えられるときは無限遠だけ考慮すれば良い。近いところは消える。
凸包の外角を計算する。
## [D - Xor Sum 2](https://beta.atcoder.jp/contests/arc098/tasks/arc098_b)
答えがoverflowした
## [Substring](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2444&lang=jp) Rolling Hash
Rolling Hashで部分文字列を高速に比較する。
## [凸多角形柱工業都市](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2827) 凸包+Dijkstra
始点から終点への辺を貼り忘れた
## [Problem E: 大玉転がし](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1157&lang=jp) 端っこだけ考える
長方形の各辺とコースの距離から大玉の直径の最大値がわかる
## [Name the Crossing](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1134&lang=jp) ワーシャルフロイド
通りA,Bが同じかどうか判定するときはグラフのコピ＾を作らないとだめ。
- 辺の追加と追加できるかの判定を同じグラフでやってしまった
## [ぼくのかんがえたさいきょうのおふとん](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2749&lang=jp) 順番がどうでもよいならとりあえずソートしてみる
需要をソートするとお布団は取り出すだけになるので(需要が減らないので)bitDPできる
- ミス一覧
メモ化再帰のキャッシュサイズを間違えた
## [Circle and Points](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1132) 円を列挙するときはギリギリのケースだけで良い
二点に接する円を列挙する。  
ミス一覧  
- 点が一つしかないケースを忘れていた
## [The Enemy of My Enemy is My Friend](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2403) 半分全列挙
ミス一覧
- 変数の初期化忘れ(特にデータセットが複数あることに起因するもの)
- 高速化できる箇所の見落とし(各頂点に関する隣接頂点bitmaskの計算)
- メモ化再帰をループに変換するときのカウンタの順序ミス
- 文字列で与えられる頂点情報の数字への変換ミス(文字列で読み込んだものはすべてmapで数字に変換しよう)
## [橋の撤去](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1196&lang=jp) 木の直径
葉っぱに付いている辺x1 + 直径x2 + その他x3。注意:C++のfor(auto e: G[i])ではeは変更できない。for(auto& e: G[i])とする必要がある。
## [夏合宿の朝は早い](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2748) 強連結成分分解→木になる
グラフを強連結成分分解すると ***木になる***。この木の葉のところの確率を全部掛けあわせたのが答え。
## [Daruma Otoshi](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1611) 長さを決めてちょっとずつ伸ばすタイプのDP
まずある範囲が落とせるかどうかをちょっとずるのばすDP  
その後どこを切るかをDP
## [500-yen Saving](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1603) DP + 回答が全順序になるタイプのDP
回答は2種類の数字の組だがその組は全順序になっている。  
最終的な答えには500円玉の最大枚数だけでなく、そのときに必要なお金の総額の最小値も必要ですが、少し工夫するだけで対応できます。具体的には、500円玉の最大枚数の表と同じ大きさの表を用意して、500円玉の最大枚数の表が更新されたときだけ更新するだけでOKです。
## [D - Grid Components](https://beta.atcoder.jp/contests/arc093/tasks/arc093_b) 発想 + 構築
  100x100のマスを半分ずつに割って必要な分だけ小さな四角形を埋め込む。言われればまあそうかという感じだが。
## [第17回JOI　予選 L番目のK番目の数](https://www.ei1333.site/problems/7) 小さい方から何番目の数$\to$$x$以下が何個?の二分探索、ぴったり$x$より$x$以下のほうが簡単
いきなりL番目を求めるのは難しい。$f(x)=$$K$番目に小さい数からなる数列の中に$x$以下の数字が何個含まれるか、を使う。$f(x)$を使えば$x$の値が二分探索できる。次に$f(x)$の計算方法を考える。数列の中に$x$以下の数が$K$個以上含まれていれば$K$番目の数は$x$以下になる。ここで数列の左端$L$を決定すると右端$R$の最小値は尺取法を使えば$O(1)$で求まる。$R$はいくら大きくしても条件を満たすので$[R,N]$が右端の範囲。
## [D - サプリメント](https://beta.atcoder.jp/contests/abc017/tasks/abc017_4) 出現頻度を条件とする尺取り法
$\text{DP}[i]$を$[f_i,f_N]$までを食べる場合の数とする。このとき$\text{DP}[i]=\sum_i^{a_i} \text{DP}[i]$である。ここで$a_i$は$f_i$と一緒に飲める組み合わせの最後の薬の番号。これを求める時に尺取り法を使う。尺取り法の条件部分にmapを使う事で出現回数に関する条件を課することができる。尺取り法は$x,y,x\le y$であって$f(x)\le f(y)$であるような$f(x)$の値を求める時に使える。あとはDPを尺取り法かsegtreeで高速化する。
## [D - 道を直すお仕事](https://beta.atcoder.jp/contests/arc026/tasks/arc026_4) 二分探索
平均の最大化問題である。時給$x$を二分探索する。$x$を固定するとある辺のコストは$C-Tx$となる。このコストの和が0より小さければOK。よってコストでソートして最小全域木を構成する。このときコストが負のものは無条件で木に追加してOKであることに注意。
## [C - バームクーヘン（Baumkuchen）](https://joi2014ho.contest.atcoder.jp/img/other/joi2014ho/joi2014ho3.pdf) 二分探索+尺取り
これは最小のピースのサイズ$x$を最大化する問題である。よって$x$について二分探索する。各$i(1\ge i\ge n)$について$i$から右回りに何個進めばサイズ$x$を超えるか($b_i$)を求める。これは尺取り法で$O(N)$で求まる。次に$x$で分割できるか調べる。これで判定できる。$O(N\log N)$。
## [みんプロ2018予選 C:駆引取引](https://yahoo-procon2018-qual.contest.atcoder.jp/tasks/yahoo_procon2018_qual_c) bitDPの高速化
$f(S,k)$=$S$の販売が停止している時の$k$番までを売って得たお金で得られる価値の最大値を求められればなんとかなる。全部買えるときは全部買えばよい。買えない時はひとつは買えない商品$t$があるので$f(S,k)=f(S\cup{t},k)$となる。この$t$を全探索すれば$O(2^N N^2)$となる。実は$3^N$のbitDPでも解ける。
## [D - 11](https://beta.atcoder.jp/contests/abc066/tasks/arc077_b) 補集合を考える
$k$個選ぶとき、補集合を考え、${}_{n+1} C_k$から重複しているものを引く。$n$種類の数字で長さ$n+1$の数列を作るので重複するのは１種類だけ。その1種類の位置を$l,r$とする。このとき重複しているのは$l<x<r$のなかから一つも選ばず、$l,r$のどちらか一つを選んだ場合。よって${}_{n+1} C_k - {}_{l-1+n-r} C_{k-1}$が答え。
## [E - 和風いろはちゃん / Iroha and Haiku](https://beta.atcoder.jp/contests/arc058/tasks/arc058_c) 補集合を考える
補集合を考える。この場合は１つもXYZを１つも含まない数列を数えればよい。直前17個の数をメモ化すると$10^17$個必要。しかし和が17以上のものはメモ化しなくてよいのでそれらを省くと、$2^17$になる。
## [AGC003 C - BBuBBBlesort!](https://beta.atcoder.jp/contests/agc003/tasks/agc003_c)
奇数番目と偶数番目を入れ替えらればあとはいいのでソートしてその数が奇数番になるか偶数番になるかを判定し、違っているものの数を数えればよい。
## [APC001 D - Forest](https://beta.atcoder.jp/contests/apc001/tasks/apc001_d)
まず各連結成分からひとつは頂点を選ばないといけない。さらに全体で頂点は$2(N-M+1)$個必要である。この条件を見たすように最小重みで選べば良い。
## [ARC049 B - 高橋ノルム君 ](https://beta.atcoder.jp/contests/arc049/tasks/arc049_b) 二分探索、長方形の重なる範囲
最小の時間$t$について二分探索する。$t$を定めると$i$さんが$(x_i,y_i)$から動ける範囲は正方形の形になる。これを$1\le i \le N$について重ねあわせる。長方形同士の重なった範囲は長方形になるので簡単に求められる。
## [サウコン D - 建物](https://soundhound2018.contest.atcoder.jp/tasks/soundhound2018_d) DP($\forall$を一つ前の添字を使って$O(1)$で計算する)
$\text{DP}[i][j] = (1,1)$から$(i,j)$に移動したときの利益の最大値とする。このとき$\text{DP}[i][j] = \max_{k\in [1,w]}(\text{DP}[i-1][k] + i\text{階で}k\to j\text{での利益}+$ $ i\text{階で}\min(k,j)\text{から左に往復することで得られる利益の最大値}+$ $i\text{階で}\max(k,j)\text{から右に往復することで得られる利益の最大値})$。$k<j$とすると左に往復するやつは$\text{DP}1[l]=P_{i,l}-2F_{i,l} + \max(0,\text{DP}1[l-1])$。右のやつは$\text{DP}2[l]=P_{i,l}-2F_{i,l} + \max(0,\text{DP}1[l+1])$で求まる。$\text{DP3}[l]=\max(\text{DP}[i-1][l],DP[i-1][l]+DP1[l-1],DP3[l-1]) + P_{i,l} - F_{i,l}$として$\text{DP}[i][j] = \max(0,\text{DP2}[j+1]) + \text{DP3}[j]$
## [ARC090 D - People on a Line](https://beta.atcoder.jp/contests/arc090/tasks/arc090_b) マージテク
- DFSで座標を決めていく
- $(l,r,d)$というクエリに対して$l$と$r$をマージする。この時小さい方の集合の座標を変更して$u$と$v$の差が$d$になるようにする。$u$と$v$が同じ集合に属しているときはその差が$d$であることをチェックする。
## [サウコン C - 広告](https://beta.atcoder.jp/contests/soundhound2018/tasks/soundhound2018_c) 最大独立集合問題
グリッドなので$(i,j)$について$i+j$の偶奇で分けると二部グラフになる。二部グラフ上で頂点を共有しない辺の集合であって大きさが最大のものを求める問題である。これは最大独立集合問題と呼ばれる。二部グラフ上の最大独立集合問題は最大流で求めることができる。
- |最大マッチング(たがいに端点を共有しない)| + |最小辺カバー(すべての頂点がカバーされている)| = |V|
- |最大安定集合(どの二点も隣接していない)| + |最小点カバー(すべての辺がカバーされている)| = |V|
- グラフが二部グラフの時 |最大マッチング| = |最初点カバー|
## [ARC090 E - Avoiding Collision](https://beta.atcoder.jp/contests/arc090/tasks/arc090_c) 最短路DAG + パスの個数
まず$S\to T$の最短路DAGを構築する。これは$S$からの全点最短距離$distS$と$T$からの最短距離$distT$を求める。また$S\to T$の最短距離を$dST$とする。このとき$distS[v] + distT[v] = dST$なら$v$は最短路DAGに含まれる。また$e=(u,v)$は$dist[u] + e.cost + dist[v] = dST$なら最短路DAGに含まれる。次に最短路DAG上で$S\to T$のパスの個数$P$を数える。高橋くんと青木くんのパスの選び方の総数は衝突するものも含めて$P^2$になる。最後に高橋くんと青木くんが衝突するパスの選び方を求める。まず頂点$v$で衝突するのは$distS[v]=dST/2$であるときに(($S\to v$のパスの個数)$\times$($v\to T$のパスの個数))$^2$である。次に辺$e=(u,v)$上で衝突するパターンは$distS[u]<dST/2<distS[v]$のときに (($S\to u$のパスの個数)$\times$($v\to T$のパスの個数))$^2$。これらを$P^2$から引く。引く数を二乗するのを忘れた。また点の場合と辺の場合を一緒に考えていた。
## [ARC074 F - Lotus Leaves](https://beta.atcoder.jp/contests/arc074/tasks/arc074_d) $x$軸と$y$軸を頂点と見る + 最大流
$x$軸と$y$軸を頂点と見ると葉$(s,t)$は$s\to t,t \to s$の辺。よって最大流で解ける。
## [天一2016予選B C - 天下一プログラマーコンテスト1999](https://beta.atcoder.jp/contests/tenka1-2016-qualb/tasks/tenka1_2016_qualB_c) 独立に計算できる事象はまとめると簡単
安藤君の結果で選手を並び替える。このとき$\textrm{DP}[i][j]=$橋本君の順位が$i$位から$N$位まで安藤君の順位と一致しており、$i-1$位の人が$j$勝している確率、とする。この時$\textrm{DP}[i][j]=\sum_{k=0}^{j-1 \text{or} j} DP[i+1][k] P(i,k)$で更新できる。$P(i,k)$は安藤君の順位で$i$の人が橋本君の結果で$k$勝する確率である。安藤君の順位で$a_i$勝していたとすると$l\ (0\le l \le a_i),m\ (0\le m\le N-1-a_i)$で$l$回勝ちの記録を間違えて、$m$回負けの記録を間違えた時の確率が計算できて$P(i,k)$が配るDPで計算できる。$O(N^3)$なので制約の間違いを疑ってしまった。
## [ARC089 D - Checker](https://beta.atcoder.jp/contests/arc089/tasks/arc089_b) 2次元累積和
まず普通に考えると盤面が大きすぎる。しかし$(x_i,y_i)$に白/黒色を塗るのと$(x_i-2K,y_i-2K)$に白/黒色を塗るのは同値。よって$2K\times 2K$の盤面を考えて$(x_i\% 2K,y_i\% 2K)$に色を塗れば良い。盤面の左下を$2K\times 2K$の範囲で動かして正しく色を塗れた点の数を数える。点を数えるのは2次元累積和を使う。解説では条件を満たす左下の範囲に1を足していって左下の最大値を取る。$\{(x,y) | x\in [x_1,x_2], y \in [y_1,y_2]\}$に1を足すには$(x_1,y_1),(x_2,y_2)$に1を足し、$(x_2,y_1),(x_1,y_2)$に-1を足す。その後$x$方向に累積和を取り、$y$方向に累積和を取れば良い。
## [AGC018 B - Sports Festival](https://beta.atcoder.jp/contests/agc018/tasks/agc018_b) シュミレーション + 単調性の発見 + ボトルネック改善
とりあえず全スポーツ開催することにする。このとき最も多くの人が参加するスポーツを除く。そして最大参加人数を数える。これを繰り返す。
## [POJ2348 Euclid's Game](http://poj.org/problem?id=2348) 1か2以上かが大違い
数$a,b (a<b)$が与えられた時
- case 1:$b\%a=0$なら勝ち
- case 2:$b\%a\neq0$のとき、$(b\%a,a)$がcase 1だったとする。このとき$b/a=1$なら負け、$1<b/a$なら勝ち。

よってより早く$1<b/a$の状況に辿りつけた人の勝ち。
## [POJ2484 A Funny Game](http://poj.org/problem?id=2484) 対象な状況を作る
場に長さ$m$の鎖が２つあった時を考える。このときAliceの番ならAliceは負である。なぜならBobはAliceと同じ行為を行うことによって対象な状況を維持できる。よって$2<n$なら必ずAliceが負ける。
## [ARC073 E: Ball Coloring](https://beta.atcoder.jp/contests/arc073/tasks/arc073_c)
まず最大値を$\text{MAX}$、最小値を$\text{MIN}$とする。青と赤を入れ替えても一般性を失わない。$R_{\text{MAX}} = \text{MAX},R_{\text{MIN}} = \text{MIN}$のときは$B_{\text{MAX}} - B_{\text{MIN}}$をできるだけ小さくしたい。これは、最初全ての袋について小さい方のボールを選んだと仮定し、それをそのなかで小さい順に並べ、順番に、そのボールを袋のもう一つのボールと交換する、ということを行えば良いです。$R_{\text{MAX}} = \text{MAX},B_{\text{MIN}} = \text{MIN}$のときはそれぞれ大きい物を赤、小さいものを青で塗る。
## [AGC016 B - Colorful Hats](https://beta.atcoder.jp/contests/agc016/tasks/agc016_b) とりあえずソートしてみる + 実験
とっかかりがつかめないのでとりあえずソートしてみる。$a_1 + 1 < a_N$はおかしい。なぜなら一人しか入れ替わっていないのに2色以上増えるはずがない。$a_1 = a_N$のときは全員の色が異なる($a_1 = N-1$)か、色的に孤立した人がいない($2a_1 \leq N$)ならOK。$a_1 + 1 = a_N$なら孤立した猫の数$x$が$x < a_N$かつ孤立してない猫の数$y$が$2(a_N - x)\leq y$ならOK。
## [第4回ドワコン予選 C - Kill/Death](https://dwacon2018-prelims.contest.atcoder.jp/tasks/dwacon2018_prelims_c) DP + 写像12相
基本的には$\text{DP}[i][j] = i$番目までに$j$個配る場合の数で良い。しかしkill数が同じプレイヤーがいた時はそのプレイヤーのdeath数は昇順になっていないといけない。これはkill数が同じプレイヤーをまとめてdeath数を配れば良い。これは[写像12相](https://mathtrain.jp/twelveway)のうちのn個の玉をk個の箱に0個以上づつ配るケースに該当し、分割数を計算することで求められる。
## [ARC081 F - Flip and Rectangles](https://beta.atcoder.jp/contests/arc081/tasks/arc081_d) XORを取ってみる + stackで長方形の面積を求めるやつ
$i$行を上端とする長方形を考える。$i$行は全部黒なので$i$行を反転させるかどうかを決めればどの列を反転させるかが決まる。列を反転させるかどうかを決めれば隣接する列とのXORがわかる。このXORは事前計算しておけば$O(1)$でわかる。XORの$i$行目以降で一番初めに1になったところを求めて、stackで長方形の面積を求めるやつをやる。stackの中身が常に単調増加する感じにしておく。$O(HW\log H)$。
## [ABC014 C - Closed Rooms](https://beta.atcoder.jp/contests/agc014/tasks/agc014_c) BFS
最初に'.'の部屋だけでBFSする。その後は任意の部屋を$K$個開ける、距離$K$だけBFSするというのを繰り返せばいい。
## [AGC020 C - Median Sum](https://agc020.contest.atcoder.jp/tasks/agc020_c) DP(部分和問題) + bitset
$D = \sum_i^N A_i$とする。このとき$A_i$の部分和で$s$が作れるなら部分集合の有無を反転することで$D-s$も作れる。$s \leq D-s$とすると$s \leq D/2 \leq D-s$なので、部分和で作れるものの半分は$D/2$以下であり、後の半分は$D/2$以上である。よって部分和で作れる$s$のうち$D/2$以上で最も小さいものが答えになる。これは01ナップサック問題(部分和問題)であり$O(ND)$かかる。これを高速化することを考える。$\text{DP}[i][j] = $を$A_1$から$A_i$までを使って$j$が作れるか?とする。このとき$\text{DP}[i][j+A[i]] |= \text{DP}[i][j];\text{DP}[i][j] |= \text{DP}[i][j];$であるが、$\text{DP}[i] = A_i$までを使って作れる部分和の集合(をbitsetでもったもの)とすると$\text{DP}[i] = 2^A_i \text{DP}[i] \text{or} \text{DP}[i]$となる。bitsetを使うことで少なくとも64bitずつまとめて計算されるので$O(ND/64)$となり間に合う。
## [第4回ドワコン予選 E - ニワンゴくんの家探し](https://dwacon2018-prelims.contest.atcoder.jp/tasks/dwacon2018_prelims_e) 重心分解
重心分解して重心に近い２つで聞くのが良い。直径でやるのはアカン…。
## [第4回ドワコン予選 D - ディスクの節約](https://dwacon2018-prelims.contest.atcoder.jp/tasks/dwacon2018_prelims_d) ビットDP
DP[$s$] = $s$の実行結果が書き込まれている状態を作り出すのに必要なディスクの容量。DP[0] = 0。遷移は$s$に含まれないタスク$i$をひとつ選んで実行し、$s$から$i$の実行に必要なタスクを消す。最小値を求める配るDPなのでダイクストラでやる。DP[1]が答え。$N < 20$なのでビットDPを疑うべき。
## [コドフェス2017予選B D - 101 to 010](https://beta.atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_d) DP + 文字列に対する考察
トークンを削除できるのは1111,...,1101or101111,...,111の形の時だけである。$\text{DP}[i]=s[i:)$から削除できるトークンの数。このとき$\text{DP}[i]=\max(\text{token}(s[i,j)) + \text{DP}[j]|\forall j(i<j))$となる。このままだと$O(|s|^2)$で間に合わない。ここで$j$の候補として11,...,11←ここ01か11,...,110ここ→1しかないことを考えると$O(N)$になる。とりあえずDPの式にしてみるというのは有効。
## [コドフェス2014予選B D - 登山家](https://beta.atcoder.jp/contests/code-festival-2014-qualb/tasks/code_festival_qualB_d) 二分探索,stackの利用
### 二分探索
部分点解法を考える。山小屋$i$から見える最も右の山小屋を求める。左側は同様にできる。求めたい山小屋の番号$j$は$w_i = \{j|i<j \wedge h_i < h_{j+1}\}$の中で最小のものである。これを愚直に求めると$O(N)$かかり全体で$O(N^2)$となるため間に合わない。ここで最も標高の高い山小屋$i_1$から$j$を求めていくことを考える。最初$w_{i_1}$は$\phi$である。$i_1$を処理したあと$w_{i_2}$には$i_1$が入る。よって$w$をstd::setで管理すれば挿入、検索が$O(\log N)$で行えて全体として$O(N \log N)$になる。検索はstd::set::upper_boundで$i$より大きい元が求まり、upper_boundでも止まったiteratorをデクリメントすれば$i$より小さい元が求まる。
### stackの利用
stackを用意する。山小屋$i$から見える最も右の山小屋を求める。これは東から順番にh[i] > h[stackの先頭]である限りstackをpopする。このあとのstackのtopが最も右の山小屋になる。山小屋$i$から見た単調増加部分列を求めるイメージ。増加部分列を求めるのにstackは使える。
## [コドフェス2014予選B C - 錬金術士](https://beta.atcoder.jp/contests/code-festival-2014-qualb/tasks/code_festival_qualB_c) ヒストグラム
まず$S_3$は並び替えられるので文字列をヒストグラムとして扱って良い。$S_1$の中の文字$c$の数を$N_{1,c}$、$S_2$の中の文字$c$の数を$N_{2,c}$、$S_3$の中の文字$c$の数を$N_{3,c}$とする。このとき$N_{1,c} + N_{2,c} \geq N_{3,c}$は必要条件。$S_1$から取ってくる$c$の文字数$n_{1,c}$は$N_{3,c} - N_{2,c} \leq n_{1,c} \leq N_{1,c}$、$n_{2,c}$は$N_{3,c} - N_{1,c} \leq n_{2,c} \leq N_{2,c}$を満たす。これらの範囲をAからZまでのすべての文字について足し算してその範囲が$N$を含むかどうか確かめれば良い。
## [コドフェス2017予選C D - Yet Another Palindrome Partitioning](https://beta.atcoder.jp/contests/code-festival-2017-qualc/tasks/code_festival_2017_qualc_d) 回文の性質をつかったDPの高速化
とりあえずDPを立式して高速化してみる?
$S[c][i] = s[0:i)$の$c$の個数とすると、$s[i,j)$が回文である条件は「$S[c][j]-S[c][i]$がすべての$c$について偶数、またはひとつの$c$についてのみ奇数」となる。この条件には偶数と奇数しか出てこないので$S[c][i]$の値としては偶奇だけを持っておけば良い。さらに$S['a'][i],S['b'][i],...,S['z'][i]$をビット列でまとめて表現して$S[i]$とする。このとき上記の条件は「$S[j]\oplus S[i]$が0または2のべき乗」となる。この条件を用いてDPする。$DP[i]=s[i:)$の最大の分割の数とする。$DP[i]=1 + max(DP[j])$(ただし$s[i,j)$は回文)で計算できる。ただしこれでは$O(|S|^2)$で間に合わない。$S[i]\oplus x$が条件を満たす$x$を列挙する。このような$x$は27通りしかない。よって$x \to DP[i]$(ただし$S[i]=x$)のmapを持っておけばDPが高速化できる。

## [ARC084 D - Small Multiple](https://beta.atcoder.jp/contests/arc084/tasks/arc084_b) グラフを作れないか疑ってみる
すべての整数は0から初めて
- 1を足す
- 10倍するという操作  

で作ることができる。それぞれの操作で各桁の和は1増える/変わらない。これでは頂点数が無限になってしまうが、今回$\text{mod} K$で等しいものは同一視できるので頂点数は$K$になる。よってこれは01BFSまたはDijkstraで求めることができる。
## [CSA Min Swaps](https://csacademy.com/contest/archive/task/min-swaps/statement/) Greedy
まず並び替えた後の数列はジグザグになってそうだということがわかる。$L_1,S_1,L_2,...,S_{N/2}$ or $S_1,L_1,...,S_{N/2},L_{N/2}$。ここで最終的に計算されるコストは$\sum_i^{N/2} 2L_i - \sum_i^{N/2} 2S_i - L_1 + S_{N/2}$ or $\sum_i^{N/2} 2L_i - \sum_i^{N/2} 2S_i - L_{N/2} + S_{1}$となる(この式を思いつけないのが痛い)。ここから$\{L_i\} = \{N/2+1,...,N\},\{S_i\} = \{1,...,N/2\}$であることがわかる。$L_1 = N/2+1,S_{N/2} = N/2$ or $L_{N/2} = N/2+1,S_{1} = N/2$は確定。他はどうでもいいのでできるだけ元の順列に近い形で並び替える。
## [CSA Amusement Park](https://csacademy.com/contest/archive/task/amusement-park/statement/) DP
DP[残りトークン数][いまどのアトラクションにいるか] = 期待値
## [Problem J: Merry Christmas](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2251) DAGの最小パス被覆
グラフ$G=(V,E)$について$F\subset E$であり$V$のすべての点が$E$に含まれるような最小の$F$を$G$の最小パス被覆と呼ぶ。この問題ではある家$v_i$にプレゼントを届けた後家$v_j$にプレゼントを届けられるなら$v_i \to v_j$の辺を貼る。これはDAGになる。ここで$v_i \to v_j$の辺を採用すると必要なサンタの人数が一人減ることがわかる。また辺の出発点、終着点はたかだか一回しか採用できないことを考えるとこれはDAGの最小パス被覆になっている。DAGの最小パス被覆は頂点を始点と終点にコピーして辺があるところに容量1の辺を貼り最大流を流せばもとまる。答えは最小パス被覆を$F$とすると$V-|F|$。
## [CF Hello 2018 D. Too Easy Problems](http://codeforces.com/contest/913/problem/D) 二分探索
解ける問題の数$s$を固定する。こうすると$s \leq a_i$である$i$について$t_i$の小さい順にとけば良い
## [B - Reverse and Compare](https://beta.atcoder.jp/contests/agc019/tasks/agc019_b) 回文の性質
$A_i = A_j$なら$A_i,...,A_j$を反転した文字列は$A_{i+1},...,A_{j-1}$を反転した文字列と同一なので、答えは$i<j \text{and} A_i \neq A_j$となる$i,j$の組の数になる。否定をとるとこれは簡単に数えることができる。$i<j \text{and} A_i = A_j$となる$i,j$の組の数を数える。$A_1,...,A_n$のなかに文字$c$が$S[n][c]$個存在したとする。$i$を固定すると条件を満たす$j$は$S[n][A_i] - S[i+1][A_i]$となる。これの$i$に関する和を$N(N-1)/2$から引けば良い。
## [B - Inscribed Bicycle](https://beta.atcoder.jp/contests/cf16-exhibition-final/tasks/cf16_exhibition_final_b) 二部探索
半径$x$の円が書けるかどうか判定する。半径$x$の円の中心が存在する範囲はは元の三角形と相似であり、その三角形は内接円の半径を$r$とすると相似比$1-x/r$である。よって$x < (1-x/r)\max(a,b,c)$で判定できる。あとはこれを使って二分探索。
## [B - Hamiltonish Path](https://beta.atcoder.jp/contests/agc013/tasks/agc013_b)
条件を満たすまでパスの端点を伸ばせば良い
## [D - Wide Flip](https://beta.atcoder.jp/contests/arc088/tasks/arc088_b)
$M$個0or1が連続している区間があったとする。このとき$M+1$個0が連続している区間をつくることができる。このように$M+1,M+2,...,N$が作れるので、答えはもっとも大きい$M$について$M+1$。
## [B - Palindrome-phobia](https://beta.atcoder.jp/contests/cf17-final-open/tasks/cf17_final_b) 回文
二文字か三文字の回文が出てこなければ良い。つまり同一文字は常に2文字以上離れていなければならない。これは'a','b','c'の出現頻度の差が1以下のとき実現できる。
## [D - ハシポン](https://tenka1-2015-quala.contest.atcoder.jp/tasks/tenka1_2015_qualA_d) 橋
まず与えられたグラフを二重連結成分分解して橋を列挙する。このとき橋が一つも無ければハシポングラフは作れない。一つ以上の橋が存在したときは二重連結成分を潰して木を作る。この木に辺を付け加えて橋をひとつだけ残す。なんとなく葉同士をくっつければ最適に橋を潰せそうな気がする。よってこの方針で行く。残す橋$e=(v,u)$を一つ決める。ここで$v$は葉であり、$u$は次数ができるだけ大きい頂点とする。$u$の条件は$e$を取り除いたときに新しくできる葉ができるだけ少なくなるものである。$e$を取り除く。$L$を葉の数とすると答えは$(L+1)/2$(切り捨て)である。これは葉同士をペアにしていく戦略からわかる。
## [No.631 Noelちゃんと電車旅行](https://yukicoder.me/problems/no/631) segtree + 最初に待っても各駅で待っても同じ
各駅で電車が来るまで待つのと駅1でまとめて待つのでは到着時間が変わらない。よって最初の駅でまとめて待つことにする。このとき駅1以外で待つことはないので待つ時間を$d$とすると駅$i$につくのは時刻$d + 3(i-1)$である。駅$i$の始発を$T_i'$とするとすべての$i$について$d + 3(i-1) \leq T_i'$なので$d \leq T_i' - 3(i-1)$である。よってすべてのクエリについて$T_i' - 3(i-1)$の最大値を求めれば良い。これは区間加算区間最大値のsegtree(Starry Sky Tree)でできる。
## [No.630 門松グラフ](https://yukicoder.me/problems/no/630) 二部グラフ=奇サイクルが存在しない
奇サイクルがあったら門松グラフにはできない。逆に奇サイクルがなかったら二部グラフなので頂点を赤と青に彩色していい感じに$a_i$を割り当てれば門松グラフになる。よって$N,M$に対して二部グラフを構成すれば良い。連結な二部グラフは$N-1\leq M \leq \frac{N(N-1)}{2}$の時に構成できる。$M = N - 1$の時グラフは木になり、$M = \frac{N(N-1)}{2}$の時グラフは密な二部グラフになる。  
## [D - 旅行会社高橋君](https://arc039.contest.atcoder.jp/tasks/arc039_d) 橋 + LCA
グラフを二重連結成分を同一視して木に変換する。この時頂点$A,B,C$が条件を満たすのは変換後のグラフで$A\to B\to C$のパスが存在するかどうかと同値になる。これは$\text{dist}(A,B) + \text{dist}(B,C) = \text{dist}(A,C)$であるかどうかと同値であり、LCAで高速に$\text{dist}(x,y)$を求められるようにしておけば良い。
## [D - Restoring Road Network](https://beta.atcoder.jp/contests/abc074/tasks/arc083_b) Warshall–Floyd
与えられた行列に対してWarshall–Floydして書き換えが起こったら最短ではない。書き換えが起こらなかった場合は最小全域木を求めれば良い。
## [D - 3N Numbers](https://beta.atcoder.jp/contests/abc062/tasks/arc074_b) priority_queue
$N\leq k < 2N$を固定する。このとき$a_i (i<k)$のなかから$N$個を前半、$a_i (k\leq i)$の中から$N$個を後半として選ぶ。前半はできるだけ和が大きいように、後半はできるだけ和が小さいように選ぶ。このような選び方は$k$をひとつずつ増やしながらpriority_queueで求めることができる。
## [D - An Ordinary Game](https://beta.atcoder.jp/contests/abc048/tasks/arc064_b) 発想
文字を１つも取り除けなくなったとき、文字列$S$は$S=$"ababababa"または$S=$"abababab"の形になっている。このゲームでは両端の文字は変化しないので最終的な文字列のぐう機は最初の文字と最後の文字の比較のみで定まる。
## [D - 桁和 / Digit Sum](https://beta.atcoder.jp/contests/abc044/tasks/arc060_b) ?進数
$b<\sqrt{n}$かどうかで場合分けする。
## [ABC021 C - 正直者の高橋くん](https://beta.atcoder.jp/contests/abc021/tasks/abc021_c) 最短路DAG
まず頂点$a$からDijkstraして全頂点への距離$d$を求める。ここですべての辺$e=(u,v)$について$d[u]=d[v]+e.\text{cost}$なら$e$を残し、そうでなければ$e$を削除する。このようにしてできたグラフを最短路DAGと呼ぶ。この最短路DAG上で$a$から$b$への経路の数を数えれば良い。
## [Good Bye 2017 D. New Year and Arbitrary Arrangement](http://codeforces.com/contest/908/problem/D) 期待値DP
$P_a = \frac{p_a}{p_a + p_b},P_b = \frac{p_b}{p_a + p_b}$とする。DP[i][j]=prefixの中に'ab'がi個、'a'がj個存在するときの'ab'の個数の期待値としてDPする。
DP[i(=aの数)][j(=abの数)] = $P_a$ DP[i][j+1] + $P_b$ DP[i+j][j]
ただしこのままでは'bbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaab'のようなケースで無限長になってしまう。そこでまず'bbbbbb'の部分は$\frac{1}{1-P_b} DP[0][1]$として処理する。'aaaaaaaa'の部分はk<=i+jのときは末尾に確定で'b'をくっつけることにする。さらにj=kのときは'a'を無限個くっつけることにして'a'の無限列に対応する。
この問題では期待値が浮動小数点ではなくmodで問われているが浮動小数点の場合と同じように計算して良い。
## [B - Unplanned Queries](https://beta.atcoder.jp/contests/agc014/tasks/agc014_b) 木上のパスはLCAをつかって分解
クエリの両端に出てくる頂点がすべて偶数回出現するかどうか。木はとりあえず根付き木にして、パスは(LCA-a)+(LCA-b)-2(根-LCA)とするのが典型。こうすることですべてのクエリは(根-a)+(根-b)とできる。(根-LCA)はmod 2で0になる。十分性は明らか。必要性を示す。書かれた数字が奇数である辺のうち最も根から遠いものを$e(=(u,v))$とする。ただし$v$が根から遠い方の頂点である。このとき$(?,v)$のクエリが必ず奇数回発行されている。
## [D - ABS](https://beta.atcoder.jp/contests/abc078/tasks/arc085_b) DP
DP[i(=あと何枚残っているか)][j(=どちらの番か)] とすると(j^1)の持っているカードはa[i-1]なのでDPできる。
## [D - Built?](https://beta.atcoder.jp/contests/arc076/tasks/arc076_b) x座標とy座標を分けて考える
最小全域木を求める問題である。しかし愚直にやると辺が$O(N^2)$本あるので間に合わない。ここでx軸とy軸に分けて考える。x座標で比較した時に$s,t,u$とならんでいるなら$s-u$の辺は必要ない。よって辺の数が$O(N)$になり最小全域木を求めることができる。
## [D - Alice&Brown](https://beta.atcoder.jp/contests/arc072/tasks/arc072_b) 実験
実験すると$|X-Y|<2$ならAliceが負けることがわかる。
## [B - Boxes](https://beta.atcoder.jp/contests/agc010/tasks/agc010_b) 操作の合計回数 + 階差数列
一回操作を行うと石が$\frac{N(N-1)}{2}$個減るので、最初にあった石を$S$個とすると操作の回数$K$は$S = K \frac{N(N-1)}{2}$になる。ここで階差数列$d_i = a_{(i+1)\%N} - a_i (1 \leq i \leq N)$を考える。一回操作を行うと$d_i$の一つが$+(N-1)$され$N-1$個が$-1$される。操作の合計回数$K$が分かっているので、一回の操作を$d_i + K$の一つを$+N$するというものに変換することができる。ここまで変換すると判定は$\forall i$について$0<d_i$かつ$d_i\% N = 0$でできる。
## [F. Tree Destruction](http://codeforces.com/contest/911/problem/F) 木の直径
[木の直径を求めるアルゴリズム](http://www.prefield.com/algorithm/graph/tree_diameter.html)から、木の最遠頂点対を $x$,$y$としたとき，$x$または$y$として$s$からの最遠頂点$u$を選んでもかまわない。ここからある頂点$s$への最長パスは$x-s$または$y-s$である。よって最遠頂点対$x,y$を求めたうえで$x-y$上に無い点sの最長パスは$x-s$または$y-s$であり、$x-y$上の点は端から削除すれば良い。
## [B - Mysterious Light](https://beta.atcoder.jp/contests/agc001/tasks/agc001_b) extgcd
最初の２辺を除くと辺の光の通った折れ線の辺の長さは$a,a,...,a,b,b,...,b,a\%b,a\%b,...,a\%b$となっていることがわかる。最初の2辺$a,b$が$a>b$のときは$a,b,a\%b,...,$となり、$a<b$のときは$a,b,a,b\%a,...,$となる。$a=b$のときは$a,a,a$で終了する。
## [C - Cheating Nim](https://beta.atcoder.jp/contests/cf16-exhibition-final/tasks/cf16_exhibition_final_c) Nim
不正者はxor和($S = a_1 \oplus a_2 ... \oplus a_n$)を0にすれば良い。このとき$b_i = a_i\oplus (a_i-1) = 2^k -1 $になることを使う。$S$のビット列を上から見て1になっているところがあれば対応する$b_i$とのxorを取る。
## [yukicoder No.573 a^2[i] = a[i]](https://yukicoder.me/problems/no/573) 数え上げ
インデックス集合$A$を$A = \bigcup A_i ( i\neq j \Rightarrow 0 = A_i \cap A_j)$と分割すると各集合のうち少なくともひとつはa[i]=iを満たす。条件を満たす場合の数は$\sum_{\text{all dividion}} \prod |A_i|$となる。ただしこれは計算するのが難しい。

$i \in X $についてa[i]=iとする。このとき$i \not \in X$となるa[i]はi以外の任意の値を取れるので$|X|^{(N-|X|)}$通りが条件を満たす。よって$\sum_{i=1}^{N} {}_N \mathrm{C}_i |X|^{(N-|X|)}$を計算すれば良い。

おまけ:[$n$個の元を持つ集合の分割の総数はベル数$B_n$になる](https://ja.wikipedia.org/wiki/%E9%9B%86%E5%90%88%E3%81%AE%E5%88%86%E5%89%B2)。$B_{n+1} = \sum_{k=0}^n {}_n \mathrm{C}_k B_k$
## [yukicoder No.417 チューリップバブル](https://yukicoder.me/problems/no/417) 木DP
```C++
rec(頂点 v,残り時間 t){
  どの子供にどれだけの時間を割り振るのが最適化を求めるナップサック問題を解く
}
```
## [ジグザグ数 (Zig-Zag Numbers)](https://www.ioi-jp.org/joi/2011/2012-yo-prob_and_sol/2012-yo-t6/2012-yo-t6.html) 桁DP
桁DPをする。先頭から0が続いた場合がコーナーケースになる。
## [No.260 世界のなんとか3](https://yukicoder.me/problems/no/260) 桁DP
桁DPをする。桁DPの基本は
```C++
dp[i][j][k][l]  //i:上からi桁目まで見ている j:A未満であることが確定している k:すでに3を選んでいる l:mod 3の値
```
こんな感じ。今回の問題ではさらに$A\le x \le B$という条件が追加されていたが、これは$B$以下の条件を満たす数から$A-1$以下の条件を満たす数を引けば良い。このためには$A-1$の文字列が必要であり以下のコードで求められる。
```C++
for(int i=SZ(A)-1;0<=i;i--){
    if('0'<A[i]){A[i]--;break;}
    else{A[i]='9';}}
```
[桁DPのわかりやすい解説](http://pekempey.hatenablog.com/entry/2015/12/09/000603)
## [B - ゲーム](https://tdpc.contest.atcoder.jp/tasks/tdpc_game) MinMax法
すぬけ君の点数を評価関数としてMinMax法を行う
## [B : Colorful Slimes](http://agc004.contest.atcoder.jp/tasks/agc004_b) パラメータを固定してみる
魔法を唱える回数$k$を固定する。このとき色$i$のスライムを得るには$\min \{a_i,a_{i-1},a_{i-2},...,a_{i-k}\}$のどこかで捕まえればよい。$\min\{a_i,a_{i-1},a_{i-2},...,a_{i-k}\}$は事前に計算できるので$O(NK)$になる。
## [G - Mixture Drug](https://beta.atcoder.jp/contests/code-thanks-festival-2017/tasks/code_thanks_festival_2017_g) 半分全列挙 + bitDP
40個なので半分全列挙できそう(思考停止)。薬品を2つのグループA,Bに分ける。|A|<=20,|B|<20。まずAの部分集合のうち毒の発生しないものを全列挙する。全列挙したAの各部分集合について混ぜても無毒なBの最大の部分集合を求めたい。Aの部分集合をA'とする。A'の薬品と混ぜても毒を発生しないBの薬品を列挙しこれをB'とする。B'の部分集合のうち毒を発生しないものを求めたい。これはbitDPでできる。
## [E. Xenia and Tree](http://codeforces.com/problemset/problem/342/E) クエリの平方分割 + LCA
クエリを平方分割する。クエリがsqrt(m)個来たら色が赤色の頂点全てからBFSして、すべての頂点から最も近い赤色の頂点までの距離を求める。これをdistとする。頂点vから最近の赤色の頂点までの距離を求めるクエリはdist[v]と未処理の赤色の頂点までの距離のminになる。未処理の赤色の頂点までの距離はLCAで求められる。
## [PKU1741 Tree](http://poj.org/problem?id=1741) 重心分解
木を重心分解して
- 重心を通るパス
- 部分木で完結するパス
- 部分木から重心へのパス  
で分類して数える。  

## [AOJ2667 F : Tree / 木](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667) EulerTour + セグメント木
EulerTourで辺を一列に並べたあと、上向きの辺と下向きの辺に分けてそれぞれ範囲加算範囲和のセグメント木をつくる。
## [E. New Year Tree](http://codeforces.com/contest/620/problem/E) EulerTour + セグメント木
部分木全てに変更する操作を行うのでEulerTourしたうえで区間更新区間ORのsegtreeを使う。区間更新区間ORは区間更新区間和のsegtreeをちょっと変更するとできる。
## [No.318 学学学学学](https://yukicoder.me/problems/no/318) セグメント木
各tについて一番左のインデックスと一番右のインデックスを覚えておいて区間更新できるセグメント木で更新する
## [E - Papple Sort](https://beta.atcoder.jp/contests/arc088/tasks/arc088_c) バブルソートの交換回数
まず、回文にできるかどうかの判定は各文字の出現回数を数えることで簡単にできる。また、回文にできるなら同じ文字をswapするのは無意味である。さらにあるS[i]が左半分にくるか、右半分に来るかはS[i]=S[j]となるインデックスjの集合を考えるとわかる。左半分のインデックスの集合を決めると、右半分のインデックスの集合も決まる。さらに左半分でswapするなら右半分でswapしても同じ数だけswapが必要になる。よってあるインデックスをどこに動かせば良いのかが一意に定まる。あとはこれをバブルソートの交換回数を求めれば良い。
## [Festivals in JOI Kingdom](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0575) 複数始点Dijkstra + 最小全域木 + LCA
まずお祭りが行われている街から複数始点Dijkstraで各街のお祭りまでの距離を求める。求めるものはs-tパスのうちパスに含まれている街のコストが最も大きいものである。ここで辺のコストを考えてみるとこれは辺の両端のうち小さい方のコストになる。よってクエリを最小全域木上で考えても良いことがわかる。今、問題は大量のクエリ(s,t)が与えられるので(s,t)間の距離を求める問題になった。これはLCAでできる。  
なおバグ。辛い。
## [E - TrBBnsformBBtion](https://beta.atcoder.jp/contests/arc071/tasks/arc071_c) 同値関係を考える、累積和
A=1,B=-1を割り当てる。AB=BA=""なのですべての文字列は数値の和で表される。さらにAAA=0,BBB=0,2=AA=BBBB=B=-1,-2=BB=AAAA=A=1なので必要な数値は-1,0,1であることがわかる。よってS,Tに対して累積和を計算しておきクエリに対してA=1,B-1の和を計算すればよい。
## [E - Decrease (Judge ver.)](https://beta.atcoder.jp/contests/arc079/tasks/arc079_c) パズル+シミュレーション
操作は$N \leq a_i$以上の要素ならどの要素に対して行っても同じであることがわかる。$a\_i$に対する操作をまとめて$a_i\le N$となるまで行う。これをすべての$a_i$が$N-1$以下になるまで行う。この操作は十分高速である。  
## [Graph Construction](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2235)  クエリの平方分割
まずクエリを$\sqrt{k}$個づつに分ける。$\sqrt{k}$のクエリをクエリブロックと呼ぶ。各クエリブロックの始点でのグラフをGとする。クエリブロックの終点までクエリを見た時に一度も分割されない連結成分はUnionFindで１つに潰す。こうしておくとクエリブロック内で処理される連結成分は頂点をUnionFindで同一視すれば、$\sqrt{k}$個ぐらいになる。クエリブロック内のクエリは単純に辺を追加/削除する。連結判定はDFSで行う。クエリブロック内に登場する頂点は$\sqrt{k}$個ぐらいなので各クエリが$\sqrt{k}$で処理でき、全体として$O(k \sqrt{k})$になる。
## [Tree - Diameter of a Tree](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A) 全方位木DP
この問題は木の直径を求める問題なのである頂点からDFSして最遠点vを求め、vから再びDFSしてvからの最遠点wをもとめてv-w間の距離が答えになる。今回はこの問題を全方位木DPで解く。  
通常の木DPは根付き木について各ノードはそのノードを根とする部分木の最適解を持つ。しかし全方位木DPではそれぞれのノードについてそのノードを根とする木を構成し、その最適解を求める。
まず木に対して通常の木DPを行いDP[v]に格納する。この後、各ノードvについてvを根とする部分木の最適解とvの親pの最適解の情報を融合してDP2[v]を求める。  
この問題の場合DP2[v]にはvを通るパスの中で最も長いパスの長さを格納する。まず通常の木DPを行い、DP[v]にvを始点とするパスの長さをすべて格納する。DP2[v]はvを始点とするパスとvの親pを始点とするパスのうちvを通らないものの最長の長さを融合して求める。  
全方位木DPにおいてはpからvに融合するための情報を渡す必要がある。大抵の場合ここがミソとなる。
## [Black White Tree](https://csacademy.com/contest/round-55/task/black-white-tree/) 全方位木DP+クエリの平方分割+LCA
色を変更するクエリが無いときは全方位木DPで答えが求められる。  
このとき黒色だけ計算すれば白色の方は引き算で計算できる。  
色を変更するクエリがあるときはクエリを平方分割して$\sqrt{Q}$個ごとに全方位木DPを行う。  
ただしDPを計算してから$\sqrt{Q}$個までのクエリにタイプ2のクエリがあった時は色を変更したすべての頂点についてLCAで距離を求める。

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
操作を逆順で考えるとk番目の人が駐車するとき1~k-1は埋まっている。よってk番目の人が駐車するときに使える辺はx-y(k<=x,k<=y)のものだけ。これを用いてUnionFindで判定する。
### ダイクストラ
パスのコストを通った頂点のうち最も大きい頂点の番号と定義する。このとき頂点iに来れるかどうかはi<=cost(S-i)で判定できる。各頂点へのコストはダイクストラで求められる。
## [D - FT Robot](https://beta.atcoder.jp/contests/arc087/tasks/arc087_b) x軸とy軸を分けて考える
x軸方向の移動とy_軸方向の移動に分けることができる。各軸についてナップサック問題を解くと到達できるかどうか判定できる。直前に回転が無い最初の前進だけは方向が選べないので注意。
## [D - No Need](https://beta.atcoder.jp/contests/abc056/tasks/arc070_b) 単調性を生かして二部探索&内部でDPする二分探索
まず$a_i \leq a_j$のとき、$a_i$が必要ならば$a_j$も必要である。つまり単調性が成り立つ。  この性質を用いると二分探索ができる。$a_i$が必要かどうかは和が$S$であって、$K \leq a_i+S \leq K+a_i$となる部分集合が存在するかどうかを判定すればよい。これはナップサック問題である。一回のナップサック問題を解くのに$O(NK)$かかるので全体として$O(NK\log N)$かかる。
## [C - だれじゃ](https://beta.atcoder.jp/contests/arc024/tasks/arc024_3) ヒストグラム
n - k + 1通りの始点に対してヒストグラムを求める。(ヒストグラム, 始点位置)の要素からなる配列を用意してソート。同じヒストグラムを持つものの中で始点が最小のものと最大のものを求めて、その差がk以上であるようなものがあれば答えはyesになる。  
## [E - Don't Be a Subsequence](https://beta.atcoder.jp/contests/arc081/tasks/arc081_c) 文字列の構成
まずaからzが少なくとも一回ずつ現れている文字列a\~zがあると、対応する答えは2文字になる。a\~z++a\~zで表される文字列があると対応する答えは3文字になる。任意の文字列について頭からa\~zがいくつ含まれているかを数えれば、答えの文字数がわかる。  
Aの任意のsuffixについて答えの文字数を計算しておく。こうすると答えの文字を先頭からgreedyに決めていくことができる。  
例えば先頭にaを持ってきたとする。A[0:]に対応する答えの長さをKとする。このときA[1:]のなかで最も小さいA[i]='a'となるiを求める。このiは事前に'a'の出現するindexを記録しておくことで高速に求められる。A[i:]に対応する答えの長さがK-1ならばOK、そうでなければ先頭に'a'を持ってくることはできない。  
はじめに答えの長さを求め、その長さになるように答えを構成するのがミソである。
## [E - 高橋君とホテル / Tak and Hotels](https://arc060.contest.atcoder.jp/tasks/arc060_c)　ダブリング
r[i][k]=i番目のホテルから$2^k$日で到達できる最も右のホテルの番号  
この配列はダブリングのテクニックで求められる。この配列を使えば各クエリを二分探索できる。  

## [D - Stamp Rally](https://agc002.contest.atcoder.jp/tasks/agc002_d) 並列二分探索
辺を増やしながら見ていくと、x[i],y[i]との連結成分の個数が初めてz[i]を超える時刻を求める問題だとわかる。  
クエリが１つの場合は辺を増やすたびにチェックすれば良いのだが、この問題でそれをやると$O(MQ)$となり間に合わない。  
そこで並列二分探索と呼ばれるテクニックを使う。  
各クエリについていつチェックするかという情報を持つ。  
そしてチェックはその時刻の時にだけ行う。  
チェックする時刻を範囲で持っておいて二分探索する。  
つまり辺を１つずつ増やしてグラフを構成する操作をlogM回繰り返す。  
こうすると全体の計算量が$O((M+Q)\log Q)$となり間にあう。
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
以上から$O(N^2 \log N)$でDPできる。  
愚直に配列を取るとlong longを$5000^2$個取るのでメモリを使いまわして節約する必要がある。
## [H - 穴あきケーキ](https://code-thanks-festival-2015-open.contest.atcoder.jp/tasks/code_thanks_festival_2015_h) 二分探索 or 尺取り法
まずある点(x,y)が与えられた時にそれより左上のカロリーの合計を計算しておく。  
こうすることでimos法を使って(x,y),(z,w)で囲まれた長方形のカロリーがO(1)でもとまる。  
カロリー1の物の数、カロリー2の物の数...を同様に記録すれば、  
ある長方形を定めた時の条件を満たす穴あきドーナツの数を$O(1)$で求めることができる。  
しかし、これでは$O(R^2 C^2)$となり間に合わない。  

### 二分探索
ここで三辺(x,y,z)を決めた時にwの取りうる範囲は精々10個しかないことに注目する。  
wを増やすとカロリーも増えるので単調性が成り立ち、二分探索ができる。
よって$O(R^2 C \log C)$で計算できる。  

### 尺取り法
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
ひとつの集合はたかだかlog N回しかマージされないので$O(Q \log N)$で抑えられる。
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
i個目のクエリを$t_i$にチェックしたとする。  
このとき条件が満たれていれば$t_i$より小さい時刻でつながっている。  
逆に大きければtiよりあとの時刻でつながっている。  
この性質を使うといつチェックするかの範囲を持っておくことで二分探索ができる。  
時間計算量は$O(QM\log t)$になる。  
いつチェックするかを時刻からクエリ番号のmapで持つことで一回あたりの計算量がならしで$O(Q)$になる。  
### 永続化配列を用いたUnionFindを使う二分探索
時刻を指定した時にその時刻の配列を復元できるような機能をもたせる。  
こうすると任意の時刻のUnionFindを復元できるので、各クエリについて二分探索ができるようになる。
## [D - Zabuton](https://cf17-final.contest.atcoder.jp/tasks/cf17_final_d) DPのための順序
制約からDPっぽいので良い順序を定めて入力を並び替える必要がありそう。  
今回はH+Pで並び替えるのが良かった。パラメータの一次式を全部試したりするのも良いかも。
## [E - MUL](https://beta.atcoder.jp/contests/arc085/tasks/arc085_c)  ProjectSelectionProblem(燃やす埋める問題)
燃やす埋める問題に帰着できる。  
[最小カットを使って「燃やす埋める問題」を解く](https://www.slideshare.net/shindannin/project-selection-problem)
>N 個の要素がある。最初どの頂点も集合 B に属しているが、これを集合 A に移すことで利益を最大化したい。  
>要素 i が A に属する時には利得 p_i を得るという情報が与えられる。  
>さらに 3 つ組の列 (xj, yj, zj) が与えられ、これは xj が A に属し、かつ yj が B に属していた時に zj(≥ 0) だけ損失をすることを意味する。  
>得られる利得の最大値を答えよ。  
[ProjectSelectionProblem](http://tokoharuland.hateblo.jp/entry/2017/11/12/234636)

## [C - Shorten Diameter](http://agc001.contest.atcoder.jp/tasks/agc001_c) 木の中心
木には中心という概念が定義できる。木の直径を$D$とすると
- $D$が偶数の時、ある頂点$v$が存在して$v$から他の頂点への距離がすべて$D/2$以下になる
- $D$が奇数の時、ある辺$e$が存在して$e$から他の頂点への距離がすべて$(D-1)/2$以下になる
この問題では中心を全探索したうえで削除すべき頂点を求めれば良い。  

## [E - 木と整数 / Integers on a Tree](https://arc063.contest.atcoder.jp/tasks/arc063_c)　木上の区間のマージ
頂点にかけられている制約はすべて[l,r]={l,l+2,l+4,...,r-2,r}とかける。この制約をDFSしながら伝搬していく。親の制約が[l,r]であったとき子の制約は[l-1,r+1]になる。途中に数字の書かれた頂点があったら区間は[v,v]の形に収束する。収束したらDFSの帰りにその制約を伝搬する。２つ以上の制約がかち合ったら共通部分を取る。このとき共通部分が空集合なら答えはNoになる。
## [C - Time Gap](https://cf17-final.contest.atcoder.jp/tasks/cf17_final_c) 鳩の巣原理
24以上は鳩の巣原理から最大値sが0になるので考えなくて良い。24以下は全探索できる。ただし23の場合だけちょっと工夫してTLEを回避する必要がある。
## [B - GCDロボット](http://ddcc2017-final.contest.atcoder.jp/tasks/ddcc2017_final_b) GCDのLCMとるやつ
いろいろ考えるとgcdのlcmをとる問題になる
## [E - すぬけ君の地下鉄旅行 / Snuke's Subway Trip](http://arc061.contest.atcoder.jp/tasks/arc061_c) 頂点を増やしてダイクストラ
各駅を乗り入れてる路線分だけコピーして改札をでるみたいな頂点を付け加えるとダイクストラできる。
## [B - Contiguous Repainting](http://agc008.contest.atcoder.jp/tasks/agc008_b)
列に対する操作は逆から見ていくといいことが多い
## [D - 切り分けできるかな？](http://arc013.contest.atcoder.jp/tasks/arc013_4) 二部グラフの最大マッチング
普通に考えると候補となる分銅の種類x2の鉄塊が必要。しかし、ある分銅がX,YにわけられるならXとYはひとつの鉄塊で作れる。よってX->Y,Y->Xに辺を貼って二部グラフの最大マッチングを求めると、マッチング数分だけ節約できる。
## [E - Grouping](http://arc067.contest.atcoder.jp/) 1/Nテクニック
愚直に考えるとO($N^3$)だが、$\sum_{i=1}^N \frac{1}{i} = N log N$なので全体として$O(N\log N)$
## [C - 3 Steps](http://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_c)　二部グラフ判定
ある$s,t$間に奇数長のパスが存在するとき$s,t$間に辺を貼ることができる。ここで任意の$s,$間に奇数長のパスが存在するかどうかはグラフの中に奇サイクルが存在するかどうかに依存する。ここで"奇サイクルが存在する" = "二部グラフでない"である。
- 二部グラフの時
  グラフの頂点を二部$A$と$B$に分ける。$A$の内部、$B$の内部に新たに辺が追加されることはないので答えは$|A||B|-M$になる。
- 二部グラフでないとき
  任意の頂点間に辺を貼ることができるので$\frac{N(N-1)}{2} - M$が答えになる。
二部グラフ判定はDFSで白と黒に塗ってみて、白と白または黒と黒が隣あっていなければ良い。
## [C. Points, Lines and Ready-made Titles](http://codeforces.com/contest/871/problem/C) x座標y座標を頂点、交点をエッジと見るやつ
グリッド系問題における、交点をエッジに変換する発想

## [C - 部門分け](http://arc056.contest.atcoder.jp/tasks/arc056_c)　$3^n$系DP
DP[S(=2^Nの部分集合)]=Sを分割して得られる信頼度の最大値、とする。  
このとき各Sについて部分集合Tを列挙する操作を行うと$O(2^N \cdot 2^N)$になると思いがち。  
しかし実際には$2^N$を３つの集合(T,S-T,U-S)に分割しているので$O(3^N)$になる。  
方法は↓  
https://kimiyuki.net/blog/2017/07/16/enumerate-sets-with-bit-manipulation/  
DP[S] = max_T ( K - (S-TとTの信頼度の和) + DP[T])  
となる。ここで(S-TとTの信頼度の和)を愚直にO(N^2)で求めると  
全体の計算量が$O(N^2 3^N) = O(37,321,507,107) = O(37G)$となり多分間に合わない。  

そこでR[S] = Sの中の信頼度の和 を計算しておく。  
すると  
(S-TとTの信頼度の和) = R[S] - R[S-T] - R[T]  
で求められる。  
## [E - Cosmic Rays](http://arc064.contest.atcoder.jp/tasks/arc064_c) ダイクストラ
$x_s,y_s$を0番目のバリア、$x_t,y_t$を$N+1$番目のバリアとする。  
このときバリアiとバリアjの間のコストをiからjに直線で動いた時に浴びる宇宙線の量とする。  
このグラフで頂点0から頂点N+1にダイクストラすればよい。  
## [E - Snuke Line](http://arc068.contest.atcoder.jp/tasks/arc068_c) segtree
まずd $\in$ [1,M]とする。  
dを固定するとN種類の名産品をひとつずつ調べることができて  
この操作はM/d*N回かかる。  
今dを1からMまで動かすと\sigma_d=1^M \frac{1}{d}  < log Mなので操作全体はO(M log M * N)かかる。  

ここであるdについて  
[1] d<=(r_i-l_i+1)なら区間iには必ず停車し  
[2] r_i-l_i<=dなら区間iには多くても一回しか停車しないことに着目する。  
よって[2]の場合を考えると  
count[N] という配列を用意して$r_i-l_i\le d$となる$i$について  
count[j]+=1 (j $\in$ [r_i-l_i])  
としてdずつ動かしてcount[N]の和を取れば良いということである。  

さらに[2]を満たす区間はdについて単調性がある。  
小さなdについて[2]なら大きなdについても[2]である。  
よってdを1からNまで動かしながらcount[N]の[2]を満たす区間に効率よく  
count[j]+=1 (j $\in$ [r_i-l_i])  
できれば良い。これはsegtreeでできる。区間加算、区間和のsegtreeである。  
## [E - Frequency](http://arc069.contest.atcoder.jp/tasks/arc069_c)
$a_i$を高さごとに分類し
$\{b_{1,i}\},\{b_{2,i}\},...,\{b_{m,i}\}$とする。
ただし$b_{1,1} < b_{2,1} < ... < b_{m,1}$である。

数列sの最初には$b_{m,1}$のインデックスxが入る。
xが何個続くのだろうか。xが続く個数をy個とする。
これは$a_i$の最大値が$b_{m-1,1}$になるまでである。
このためには$b_{m,?}$の各要素から$b_{m,1}-b_{m-1,1}$を引けば良い。よって
$y=(b_{m,1}-b_{m-1,1})\times(\text{number of }b_{m,?})$となる。
xがy個続いたあとは数列の最大値は$b_{m-1,1}$になっている。
つまり$b_{m-1,?}$の個数が$b_{m,?}$の個数分だけ増えることになる。
次にアルゴリズムの最初に戻ってやり直せば良い。

このアルゴリズムの実行時間は分類に$O(n log n)$、数列sの構成に$O(n)$かかるので$O(n log n)$である。実際に実装するときは$b_{i,j}$の（値、個数、$b_{i,1}$)のインデックスの組だけを記録すれば良い。
## [E - Meaningful Mean](http://arc075.contest.atcoder.jp/tasks/arc075_c) 座標圧縮 + segtree
まずすべてのiについて$a_i-=K$とする。そして累積和$s_i$を求める。このとき$[i,j]$で条件を満たすのは$s_i \leq s_j$となる$i,j$である。さらに$s_i$の値をすべて座標圧縮したものに置き換える。座標圧縮によって値の範囲は0~N-1になる。座標圧縮しても$i,j$の条件は変わらない。ここで数列を後ろから見ていく。$[k,i]$で条件を満たす$i$を探すとき、$s_{i+1}...s_{N-1}$までをsegtreeに入れておく。$s_x$をsegtreeにいれるとはsegtree[$s_x$]+=1を意味する。 こうすることで$[k,i]$の条件を満たすiの個数は$\sum(s_k,\inf)$となる。segtreeへの挿入&和の操作がlog Nなので全体で$O(N\log N)$で解ける
## [E - Connected?](http://arc076.contest.atcoder.jp/tasks/arc076_c) カッコの対応問題
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
具体的には $p_1 p_2 p_3 .... p_n$ としたとき一番最後に取り出される$p_i,p_j$は
つぎの条件を満たす。  
$p_1,..,p_{i-1}$は取り出されている。つまり$i-1$は2で割り切れる  
$p_{i+1},...,p_{j-1}$は取り出されている。つまり$j-i-1$は2で割り切れる
よって次のことが言える  
$i\%2=1,j\%2=0$ (1-indexedで書いていることに注意)  
以上から$i\%2=1$であり数値が最小のもの$i$と$j\%2=0$であり$i<j$であり$p_j$が最小のものをとり出せばよい  

$p_i$と$p_j$を取り出した数列に対しても同じことをすれば良いのだが上のアルゴリズムを愚直に実装すると$N^2$かかる  

ここで$p_i$と$p_j$を取り出すと数列は$A=\{p_1,...,p_{i-1}\},B=\{p_{i+1},...,p_{j-1}\},C=\{p_{j+1},...,p_n\}$に分割され
$A$と$B$から要素を取ってきたり,$A$と$C$から、$B$と$C$から取ってくることはない。  
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


## [サッカー(Soccer)](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0639) 拡張ダイクストラ
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
## [C - ウサギ跳び](https://beta.atcoder.jp/contests/arc041/tasks/arc041_c)　発想
背中合わせのうさぎは互いに影響しない。  
よってRRR....LL/RR..LL/R.....LLLのように分割したうえで各ブロックについてR/Lのうち多い方をジャンプさせれば良い。
## [D - Non-decreasing](https://beta.atcoder.jp/contests/arc086/tasks/arc086_b) 発想
全部正なら$a_2+=a_1;a_3+=a_2;...a_N+=a_{N-1};$で良い。  
全部負なら$a_{N-1}+=a_N;a_{N-2}+=a_{N-1};...;a_1+=a_2;$で良い。  
つまり全部の符号を揃えれば良さそう。これは絶対値の最も大きい物をすべてに足せば良い。  
思いつきはしたが、得られるものは特にない。

## [C - Z塗り](https://arc040.contest.atcoder.jp/tasks/arc040_c) 発想
上の行から見ていって，まだ塗られていない最も右のマスを探し，そこを起点にして塗る．
## [D - Menagerie](https://arc069.contest.atcoder.jp/submit)　発想
連続する２つがわかれば全部確定する
## [C - Knot Puzzle](http://agc002.contest.atcoder.jp/tasks/agc002_c) 発想
$a_i + a_{i+1} \ge L$であればPossible、そうでなければImpossible

## 蟻本の復習
- setのk番目を求めたいときはg++拡張のtreeが使える
  <http://hogloid.hatenablog.com/entry/2014/09/23/132440>
  <https://gcc.gnu.org/onlinedocs/gcc-4.6.4/libstdc++/api/classes.html>
  を参照せよ
- 蟻本p219 式変形で1対1割当の最小コストを求める問題に変形→二部グラフの最小費用流
- 蟻本p217 フローfがその流量における最小費用流=fの残余グラフに負閉路が存在しない
- 蟻本p212 ProjectSelectionProblem
  $N$個の要素がある．最初どの頂点も集合$B$に属しているが，これを集合$A$に移すことで利益を最大化したい． 要素$i$が$A$に属する時には利得$p_i$を得るという情報が与えられる． さらに3つ組の列$(x_j,y_j,z_j)$が与えられ，これは$x_j$が$A$に属し，かつ$y_j$が$B$に属していた時に$z_j(\ge0)$だけ損失をすることを意味する． 得られる利得の最大値を答えよ．
  要素に対応するものとS,Tで合計N+2個の頂点を用意する。 要素がAに属するとき対応する頂点を赤、Bに属するとき青で塗るとする。制約は次のようにして帰着させられる:
  「Aに属するとき利得pi≥0を得る」は無条件の利得piを準備し重みpiの有向辺S→xiを張る
  「Aに属するとき利得pi≤0を得る」は重み|pi|の有向辺xi→Tを張る
  「xjがAに属しかつyjがBに属していた時にzj(≥0)だけ損失」は重みzjの有向辺xj→yjを張る
- 蟻本p210 2種類のもの(飲み物と食べ物)を1種類のものに割り当てる問題
- 蟻本p206 座標$\times$時間を頂点とする+二部グラフの最大マッチング
- 蟻本p205 グリッド系問題における交点を辺に変換するやつ+最小辺カバー(点を全部カバー)=最大マッチング(@二部グラフ)
- 蟻本p182 数列の一般項を行列で表すことができれば繰り返し二乗法で高速に解ける。DPとか
- 蟻本p172 接点が列を持っているsegtreeを領域木と呼ぶことがある。
  区間$[l,r)$の$v$以下の数の個数を計算せよ=$l\le x< r,y<v$の領域に含まれる点の個数を計算せよ
- 蟻本p168 列を分割してソートしておくと二分探索ができる。segtreeでも平方分割でも可。segtreeは各接点に列を持つ。マージソートの過程を保存する感じ。
- 蟻本p167 平方分割でもRMQが実現できる
- 蟻本p165 一般に操作による累積和の変化が位置のn次式で表すことができるとき、n+1個のBITで対処できる場合がある
- 蟻本p162 反転数はBITで数えることができる
- 蟻本p156 結合則が成り立つならsegtreeに載せられる
- 蟻本p149 半分全列挙した後、明らかにいらないものを除くと扱いやすくなる。
- 蟻本p147 4つのうち２つを選ぶ組み合わせを全列挙して二分探索
- 蟻本p145 弾性衝突 弾性衝突はとりあえずすり抜けに置き換える
- 蟻本p132 平均最大化
  平均$x$を定めると$\sum_{i\in S} v_i / \sum_{i\in S} w_i \ge x$となる$S$を求める問題。
  これは$\sum_{i\in S}(v_i -xw_i)\ge 0$であり、$(v_i-xw_i)$でソートしておけばよい。
- 蟻本p113 区間内の素数の個数 $[2,\sqrt{b})$の素数の表を持っておけば$[a,b)$の素数を求めることができる。
- 蟻本p107 線分上の格子点の個数 最大公約数を使う
- 蟻本p105 Layout
  両辺に一つづつしか変数が現れない不等式を最短経路問題に変換する。
- 蟻本p85 食物連鎖
  各動物$i$について動物$i$が種類Aである、Bである、Cであるの3種類の頂点を作りUnionFindで条件の妥当性を検証する
- 蟻本p67 重複組み合わせ（個数制限あり) DPを高速化するやつ
- 蟻本p66 分割数(n個の区別できない品物をm個の箱に入れるやり方) [写像12相](https://mathtrain.jp/twelveway)を参照
- 蟻本p63 最長増加部分列問題
  DP[i] = 長さがi+1であるような増加部分列における最終要素の最小値とすることでDP[i]は常に単調増加するので二分探索で更新出来て$O(n\log n)$。
- 蟻本p62 個数制限付き部分和問題
  DP[i+1][j] = i番目まででjを作るときにあまる最大のi番目の個数
- 蟻本p60 01ナップサック問題その2
  DP[品物のindex][価値] = 実現する最小の重さ(存在しない場合はINF)
- 蟻本p59 個数制限なしナップサック問題
  無駄な計算の削減でオーダーが落とせて$O(nW)$。
- 蟻本p49 Fence Repair
  ハフマン符号と同様に最も小さいもの２つをくってつけていく
- 蟻本p45 Best Cow Line
  反転して比較する発想
- 蟻本p43 区間スケジューリング問題
  終了時間が早いものから選ぶ
- 蟻本p144 $n$個のサイズ$k$の部分集合
- 蟻本p27 くじびき
  $n$個の数字$a_i$から重複を許して４つ取り出すとき合計を$m$にすることはできるか?２つの数で作れる数を列挙しておけば二分探索を使って$O(n^2\log n)$。

  # 未解決問題
  ## 700点
  - [C - Nuske vs Phantom Thnook](https://beta.atcoder.jp/contests/agc015/tasks/agc015_c)
  - [C - +/- Rectangle](https://beta.atcoder.jp/contests/agc016/tasks/agc016_c)
  - [E - ConvexScore](https://beta.atcoder.jp/contests/arc082/tasks/arc082_c)
  - [F - Sandglass](https://beta.atcoder.jp/contests/arc082/tasks/arc082_d)
  - [D - Four Coloring](https://beta.atcoder.jp/contests/code-festival-2017-quala/tasks/code_festival_2017_quala_d)
  - [E - Prefix-free Game](https://beta.atcoder.jp/contests/arc087/tasks/arc087_c)
  ## 600点
  - [D - Decrease (Contestant ver.)](https://beta.atcoder.jp/contests/arc079/tasks/arc079_b)
  - [D - 11](https://beta.atcoder.jp/contests/abc066/tasks/arc077_b)
  - [D - Xor Sum](https://beta.atcoder.jp/contests/arc066/tasks/arc066_b)
  ## 500点
  - [D - IntegerotS](https://beta.atcoder.jp/contests/tenka1-2017/tasks/tenka1_2017_d)
  - [D - 井井井 / ###](https://beta.atcoder.jp/contests/abc058/tasks/arc071_b)
  ## 400点
  - [D - Insertion](https://beta.atcoder.jp/contests/abc064/tasks/abc064_d)
  - [B - Median Pyramid Easy](https://beta.atcoder.jp/contests/agc006/tasks/agc006_b)
  - [D - いろはちゃんとマス目 / Iroha and a Grid](https://beta.atcoder.jp/contests/abc042/tasks/arc058_b)
  - [D - アンバランス / Unbalanced](https://beta.atcoder.jp/contests/arc059/tasks/arc059_b)
  - [D - Card Eater](https://beta.atcoder.jp/contests/arc068/tasks/arc068_b)
  - [D - 高橋君と見えざる手 / An Invisible Hand](https://beta.atcoder.jp/contests/abc047/tasks/arc063_b)

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
## 集合分割問題
[入力] 有限集合 $U$ の部分集合 $S_1, ..., S_r$  
[出力] $S_i$ のうちいくつかで $U$ 全体をちょうど覆うことはできるか？
## 2SAT
強連結成分分解に落ちる
## Post の対応問題(決定不能)
[入力] $\{0,1\}$ の列たち $a_1, ..., a_r, b_1, ..., b_{r}$  
[出力] $a_{i_1},a_{i_2}...a_{i_k} = b_{j_1},b_{j_2}...b_{j_k}$ となるような $i_1,i_2, ..., i_k (k > 0)$ は存在するか？ (${i},{j}$ は同じ値を複数回含んでもよい)  

# 解法が浮かばない時に試すことリスト
## シュミレーション問題
- 1ステップごとのシュミレーションの高速化
  - データ構造
- 複数ステップをまとめる
  - 被ってる部分をまとめる
  - ダブリング
- ステップ回数を減らす
  - ループの検出
## Yes or No
- 探索・DP
  - 全部調べられる場合
- 戦略決め打ち
  - 貪欲
- グラフ
  - 到達可能性
  - 最大マッチング
- 最小・最大問題になっている
## 最小・最大
- 整数値・実数値
  - 探索・DP
  - 数学
  - 貪欲
  - データをソートして尺取り
  - 二分探索
  - グラフ
    - とりあえずグラフにして最短経路/最小全域木/最大流/最小費用流
  - 畳み込み
  - 辞書順最小もこっち
## 組み合わせの個数
  - 全探索
  - 数学(Combination/Permutation)
  - 含除原理
  - 最大・最小と組み合わせの個数
    最大値とその組み合わせを記録するDP
## 確率
  - 全探索・メモ化
  - とりあえずソートして貪欲
  - 枝狩り
  - 数学
## 期待値
  - 線形性
  - 確率と平均値をもってDP
## ゲームの勝敗判定(二人零和有限確定完全情報ゲーム)
  - MinMax法
  - Grundy法
  - 必勝法で発見する
## 答えのうち一つ(任意の解)
  - 全探索・枝狩り
  - 決め打ち
  - 最小問題を解いて復元
## 参考動画
[https://www.youtube.com/watch?v=_Je4rukUcqE](ワンランク上に行くプロコン講座)

# これから勉強したいアルゴリズム・定理
- Heavy Path Decomposition
- コストが負の辺を含む時の最短経路
- オイラー閉路の存在判定と構成
- 最小有向木
  最小全域木の有向グラフ版で、指定された頂点からすべての頂点に到達できるようなもの。
- 最小シュタイナー木
  最小全域木の一般化版で指定された頂点を連結にする重み最小の木。
- 関節点
  取り除くと連結成分の個数が増加するような頂点・辺のこと。
- 黄金分割法
  凸関数の極値を求める手法。
- Suffix Array
- Treap Tree
- Splay Tree
- Link-Cut Tree
- 木の重心分解
- Least Common Ancester
- 2-SAT
- 最小点カバー
- 辺彩色
- 永続的なデータ構造
- ウェーブレット行列
- FFT
# もう知っているアルゴリズム・定理
- ハンガリアン法
  人 1 ... n と仕事 1 ... n がある．人 i を仕事 j に割り当てたときの利益が a[i][j] であるとする．このとき，すべての人を，それぞれ異なる仕事につかせることによって，得られる利益を最大化する問題を割り当て問題という．この問題は，二部グラフの最大重みマッチングの特殊な場合であると考えられる．すなわち，二部グラフの両側の頂点数が等しく，完全グラフである場合が割り当て問題である．ハンガリアン法は最小費用流問題に対する主双対法を，行列ベースで書き下したアルゴリズムだと理解することもできる．
- 最大マッチング
- 最小コスト最大マッチング
- 最小カットが最大フローに一致する
  <http://kupc2016.contest.atcoder.jp/tasks/kupc2016_e>
  塀を設けるのが辺ではなくグリッドの中央なので、グリッドごとに裏から表に容量1の辺を貼る工夫が必要。
  <http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2251>
  二部グラフの最大マッチング問題。ワーシャルフロイドは
  REP(k,N)REP(i,N)REP(j,N)
    d[i][j]=min(d[i][k]+d[k][j],d[i][j])
  の形で書かないといけない。i,j,kの順番でループを回すとバグる。
- 最小全域木
- 二点間最短経路
- 全点間最短経路
- Segment Tree
- 最小費用流
  時間計算量$O(F|E|\log|V|)$
- 強連結成分分解
  時間計算量$O(|V|+|E|)$。アルゴリズム自体はトポロジカルソートしてから逆グラフ?に対してDFSする。つまりDFSx2。

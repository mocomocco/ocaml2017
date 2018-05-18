(*目的:原点から受け取った座標pairまでの距離を求める*)
(*kyori:float*float->float*)
let kyori pair =match pair with 
(a, b) -> sqrt (a *. a+. b *.b)

(*テスト*)
let test1 = kyori(3.0, 4.0) = 5.0
let test2 = kyori(5.0, 12.0) = 13.0
let test3 = kyori(8.0, 15.0) = 17.0


(*学生ひとり分のデータを表す型*)
type gakusei_t = {
namae : string;(*名前*)
tensuu : int;(*点数*)
seiseki : string;(*成績*)
}

(*学生データの例*)
let gakusei1 = {namae="asai"; tensuu=70; seiseki="B"}
let gakusei1 = {namae="tanaka"; tensuu=90; seiseki="A"}
let gakusei1 = {namae="yamada"; tensuu=60; seiseki="C"}

(*目的：学生の成績データを受け取ったら、成績通知文を返す*)
(*tsuuchi : gakusei_t -> string*)
let tsuuchi gakusei = match gakusei with 
{ namae=n; tensuu=t; seiseki=s}-> n ^ " さんの点数は "^string_of_int t^ " 点で成績は "^s^" です。"

(*テスト*)
let test1 = tsuuchi gakusei1 ="asai さんの点数は 70 点で成績は B です。"
let test1 = tsuuchi gakusei1 ="tanaka さんの点数は 90 点で成績は A です。"
let test1 = tsuuchi gakusei1 ="yamada さんの点数は 60 点で成績は C です。"

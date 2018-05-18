type jikoku_t =
Gozen of int
|Gogo of int
|Noon
|Midnight
let jikoku24 jikoku = match jikoku with
Gozen (n) ->n
|Gogo (n) ->n+12
|Noon -> 12
|Midnight -> 0

type tree_t =Empty
|Node of tree_t * int * tree_t

let t0=Node (Empty,0,Empty)
let t1=Node (Empty,3,Empty)
let t2=Node (Empty,7,t1)
let t3=Node (Empty,24,Empty)
let t4=Node (t2,17,t3)

(*目的：木の中の整数の合計を返す*)
(*sum_tree : tree_t -> int*)
let rec sum_tree tree=
match tree with
Empty ->0
| Node (l,n,r) -> n+ sum_tree l + sum_tree r



(*テスト*)
let test0 =sum_tree t0 = 0
let test1 = sum_tree t1 =3
let test2 = sum_tree t2 = 10
let test3 = sum_tree t3 =24
let test4 = sum_tree t4 =51

let t20=Node (Empty,0,Empty)
let t21=Node (Empty,7,Empty)
let t22=Node (Empty,3,t21)
let t23=Node (Empty,24,Empty)
let t24=Node (t22,17,t23)

(*目的：treeの中に受け取った数字mがあるか調べる*)
(*search : tree_t -> int -> bool*)

let rec search tree m = match tree with
Empty->false
|Node (l,n,r)->if n=m then true
else if m<n then search l m
else search r m


let test0 =search t20 0 = true
let test1 =search t24 17 = true
let test2 =search t24 7 = true
let test3 =search t24 5 = false
let test4 =search t24 20 = false

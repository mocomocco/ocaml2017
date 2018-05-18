#use "metro.ml"

type eki_t = {
  namae : string*string;(*漢字の駅名の文字列と県名の文字列のペア*)
  saitan_kyori : float;(*最短距離*)
  temae_list : (string*string) list; (*駅名ペアのリスト*)
}

let local_ekimei_list=[
{kanji="新宿"; kana="しんじゅく"; romaji="shinjuku"; ken="東京"; shozoku="中央線"};
{kanji="中野"; kana="なかの"; romaji="nakano"; ken="東京"; shozoku="中央線"};
{kanji="高円寺"; kana="こうえんじ"; romaji="kouenji"; ken="東京"; shozoku="中央線"};
{kanji="阿佐ヶ谷"; kana="あさがや"; romaji="asagaya"; ken="東京"; shozoku="中央線"};
{kanji="荻窪"; kana="おぎくぼ"; romaji="ogikubo"; ken="東京"; shozoku="中央線"};
{kanji="新宿"; kana="しんじゅく"; romaji="shinjuku"; ken="東京"; shozoku="丸ノ内線"};
{kanji="西新宿"; kana="にししんじゅく"; romaji="nishi-shinjuku"; ken="東京"; shozoku="丸ノ内線"};
{kanji="中野坂上"; kana="なかのさかうえ"; romaji="nakano-sakaue"; ken="東京"; shozoku="丸ノ内線"};
{kanji="新中野"; kana="しんなかの"; romaji="shin-nakano"; ken="東京"; shozoku="丸ノ内線"};
{kanji="東高円寺"; kana="ひがしこうえんじ"; romaji="higashi-koenji"; ken="東京"; shozoku="丸ノ内線"};
{kanji="新高円寺"; kana="しんこうえんじ"; romaji="shin-koenji"; ken="東京"; shozoku="丸ノ内線"};
{kanji="南阿佐ヶ谷"; kana="みなみあさがや"; romaji="minami-asagaya"; ken="東京"; shozoku="丸ノ内線"};
{kanji="荻窪"; kana="おぎくぼ"; romaji="ogikubo"; ken="東京"; shozoku="丸ノ内線"}
]
let local_ekikan_list=[
  {kiten="新宿"; kenk="東京"; shuten="中野"; kens="東京"; keiyu="中央線"; kyori=4.4; jikan=6};
{kiten="中野"; kenk="東京"; shuten="高円寺"; kens="東京"; keiyu="中央線"; kyori=1.4; jikan=2};
{kiten="高円寺"; kenk="東京"; shuten="阿佐ヶ谷"; kens="東京"; keiyu="中央線"; kyori=1.2; jikan=2};
{kiten="阿佐ヶ谷"; kenk="東京"; shuten="荻窪"; kens="東京"; keiyu="中央線"; kyori=1.4; jikan=2};
  {kiten="荻窪"; kenk="東京"; shuten="西荻窪"; kens="東京"; keiyu="中央線"; kyori=1.9; jikan=2};
  
{kiten="新宿"; kenk="東京"; shuten="西新宿"; kens="東京"; keiyu="丸ノ内線"; kyori=0.8; jikan=1};
{kiten="西新宿"; kenk="東京"; shuten="中野坂上"; kens="東京"; keiyu="丸ノ内線"; kyori=1.1; jikan=2};
{kiten="中野坂上"; kenk="東京"; shuten="新中野"; kens="東京"; keiyu="丸ノ内線"; kyori=1.1; jikan=2};
{kiten="新中野"; kenk="東京"; shuten="東高円寺"; kens="東京"; keiyu="丸ノ内線"; kyori=1.0; jikan=1};
{kiten="東高円寺"; kenk="東京"; shuten="新高円寺"; kens="東京"; keiyu="丸ノ内線"; kyori=0.9; jikan=1};
{kiten="新高円寺"; kenk="東京"; shuten="南阿佐ヶ谷"; kens="東京"; keiyu="丸ノ内線"; kyori=1.2; jikan=2};
{kiten="南阿佐ヶ谷"; kenk="東京"; shuten="荻窪"; kens="東京"; keiyu="丸ノ内線"; kyori=1.5; jikan=2}
]


(* 目的：ローマ字の文字列による駅名と駅名リスト（前回、 作った ekimei_t 型のもののリスト）を受け取ったら、 その駅の漢字表記（文字列）と県名（文字列）のペアを 返す  （駅名リストにその駅が見つからないときには、 どちらも空文字列のペア ("", "") を返すことにする。） *)
(* romaji_to_kanji2   : string -> ekimei_t list -> string*string *)
let rec romaji_to_kanji2   name lst =match lst with
    [] -> ("","")
  |{kanji=c;ken=k;romaji=r;kana=j;shozoku=s} :: rest
    -> if r=name then (c,k)
    else romaji_to_kanji2 name rest;;


(* 目的：駅名ペアをふたつと駅間リストを受け取って来たら、 駅間リストの中からその２駅（ペア）間の距離を返す *)
(*  get_ekikan_kyori2 : string * string -> string * string -> ekikan_t list -> float *)
let rec  get_ekikan_kyori2 st1 st2 lst = match lst with
  [] -> infinity
  |{
  kiten=s; (* 起点 *)
  kenk=sk; (* 起点の県名 *)
  shuten=g; (* 終点 *)
  kens=gk; (* 終点の県名 *)
  keiyu=a; (* 経由路線名 *)
  kyori=d;  (* 距離 *)
  jikan=h;    (* 所要時間 *)
}::rest -> match (st1,st2) with
    ((f,b),(c,e))->if (f=s && b=sk && c=g && e=gk)||(c=s && e=sk && f=g &&b=gk)
    then d
    else get_ekikan_kyori2 st1 st2 rest;;

(* 目的：ekimei_list を受け取ったら、その駅名を使って eki_t 型の リストを作る *)
(* make_eki_list2 : ekimei_list -> eki_t list *)
let rec make_eki_list2 lst =match lst with
    []->[]
  |{kanji=name1; ken=name2} :: rest -> {namae=(name1,name2);saitan_kyori=infinity;temae_list=[]} :: make_eki_list2 rest


(* 目的： eki_t 型のリストと起点の駅名ペアを受け取ったら、 起点のみsaitan_kyori を 0. に、temae_list を起点の駅名ペアのみにして、 起点以外はもとと同じであるような要素が eki_t 型のリストを返す *)
(* shokika2 : eki_t list -> (string*string) -> eki_t list *)
let rec shokika2 lst pair =match pair with (a,b)->
match lst with
  [] -> []
| first :: rest ->
  match first with {namae = (eki,ken)} ->
  if (a=eki && b=ken)
  then {namae = (a,b); saitan_kyori= 0.;temae_list=[(a,b)]} :: rest
                                                     else first :: (shokika2 rest pair)

(* 目的：（直前に最短距離を確定した）点 p（eki_t 型）と 最短距離が未確定の点 q（eki_t 型）、および 駅間のリスト（ekikan_t list 型）を受け取ったら、 get_ekikan_kyori2 を使って q が p に接続しているかを調べ、 接続していたら最短距離と手前リストを更新したq を 返す。 *)
(* koushin1 : eki_t -> eki_t -> ekikan_t list -> eki_t *)
let koushin1 p q lst =
  match p with
      {namae=np;saitan_kyori=dp ;temae_list=lstp}->
      match q with
        {namae=nq ;saitan_kyori=dq ;temae_list=lstq}->
        let d=(get_ekikan_kyori2 np nq lst)  in
        if (d=infinity) then q 
        else
        if (dq < d+.dp) then q
          else {namae=nq;saitan_kyori=d+.dp;temae_list=nq::lstp}
 
let koushin2 p q lst = koushin1 p lst q

(* 目的：（直前に最短距離を確定した）点 p（eki_t 型）と 最短距離が未確定の点の集合 V（eki_t list 型）、および 駅間のリスト（ekikan_t list 型）を受け取ったら、 V 中の全ての駅について、必要に応じて更新処理を行った後の 未確定の駅の集合を返す関数 *)
(* koushin : eki_t -> eki_t list -> ekikan_t list -> eki_t list *)
let koushin p v lst =List. map (koushin2 p lst) v

             

(* 目的：すでに県名の文字列に関してレコードが昇順に並んでいるリスト lst とレコード n を 受け取ったら、lst を前から順に見ていき、 昇順になる位置に n を挿入したリストを返す(重複した場合はここで取り除く) *)
(* insert :  ekimei_t list -> ekimei_t -> ekimei_t list *)
let rec insertk lst n =match lst with
    [] -> [n]
  |first :: rest ->
    match first with {kanji = c1; kana = j1; romaji = r1; ken =k1; shozoku =s1}->
    match n with {kanji = c; kana = j; romaji = r; ken =k; shozoku =s}->
        if k1 > k then n :: first :: rest
        else if k1 < k then first :: insertk rest n
        else if c1 > c then n:: first :: rest
        else if c1 < c then first :: insertk rest n
else first :: rest

                                                       
                                              
(* 目的：ekimei_list を受け取ったら、それを整列し、 さらに重複した駅を取り除いた  *)
(* seiretsu2 : ekimei_list -> ekimei_list *)
  
let rec seiretsu2 lst = match lst with
    [] -> []
  |first :: rest -> insertk (seiretsu2 rest) first

let local_eki_list=shokika2 (make_eki_list2 (seiretsu2 local_ekimei_list)) ("荻窪","東京");;
 
    
let global_eki_list=shokika2 (make_eki_list2 (seiretsu2 global_ekimei_list)) ("荻窪","東京")







(* 目的：eki_t list 型のリストを受け取ったら、 「最短距離最小の駅」と「最短距離最小の駅以外からなるリスト」の組 （(eki_t * eki_t list) 型）を返す関数 saitan_wo_bunri2 を デザインレシピに従って作れ。 *)

(* saitan_wo_bunri2 : eki_t list -> eki_t * eki_t list *)

let rec saitan_wo_bunri2 lst = match lst with
    []->({namae=("","");saitan_kyori=infinity;temae_list=[]},[])
  |first :: rest ->
    match first with {saitan_kyori = s;}->
    match saitan_wo_bunri2 rest with
      (rfirst,rlst)->
      if rfirst={namae=("","");saitan_kyori=infinity;temae_list=[]} then (first,[])              
      else  match rfirst with
       {saitan_kyori=rs}->
      if(rs<s)then(rfirst,first::rlst)
      else(first,rest)

(* テスト *)         


(* 目的：起点のみ最短距離が 0 で他は infinity となっている 駅のリスト（eki_t list 型） と駅間リスト（ekikan_t list 型） を受け取ったら、 （上に述べた方針に従ってダイクストラ法を動かし、最終的に） 「起点からの最短距離と『起点からその駅に至る 駅名の（逆順の）リスト』が入った駅」のリスト（eki_t list 型）を返す *)
(* dijkstra_main : eki_t list -> ekikan_t list -> eki_t list *)

let rec dijkstra_main ekilst ekikanlst =
  let pair=saitan_wo_bunri2 ekilst
  in match pair with  (a,lst)->
    match lst with
      []->if a={namae = ("", ""); saitan_kyori = infinity; temae_list = []} then[]
      else [a]
    |first::rest->
      let reclist=dijkstra_main (koushin a lst ekikanlst) ekikanlst
          in a::reclist

(* テスト *)


let test1=dijkstra_main local_eki_list local_ekikan_list
    =  [{namae = ("荻窪", "東京"); saitan_kyori = 0.;
    temae_list = [("荻窪", "東京")]};
   {namae = ("阿佐ヶ谷", "東京"); saitan_kyori = 1.4;
    temae_list = [("阿佐ヶ谷", "東京"); ("荻窪", "東京")]};
   {namae = ("南阿佐ヶ谷", "東京"); saitan_kyori = 1.5;
    temae_list = [("南阿佐ヶ谷", "東京"); ("荻窪", "東京")]};
   {namae = ("高円寺", "東京"); saitan_kyori = 2.59999999999999964;
    temae_list =
     [("高円寺", "東京"); ("阿佐ヶ谷", "東京");
      ("荻窪", "東京")]};
   {namae = ("新高円寺", "東京"); saitan_kyori = 2.7;
    temae_list =
     [("新高円寺", "東京"); ("南阿佐ヶ谷", "東京");
      ("荻窪", "東京")]};
   {namae = ("東高円寺", "東京"); saitan_kyori = 3.6;
    temae_list =
     [("東高円寺", "東京"); ("新高円寺", "東京");
      ("南阿佐ヶ谷", "東京"); ("荻窪", "東京")]};
   {namae = ("中野", "東京"); saitan_kyori = 3.99999999999999956;
    temae_list =
     [("中野", "東京"); ("高円寺", "東京");
      ("阿佐ヶ谷", "東京"); ("荻窪", "東京")]};
   {namae = ("新中野", "東京"); saitan_kyori = 4.6;
    temae_list =
     [("新中野", "東京"); ("東高円寺", "東京");
      ("新高円寺", "東京"); ("南阿佐ヶ谷", "東京");
      ("荻窪", "東京")]};
   {namae = ("中野坂上", "東京"); saitan_kyori = 5.69999999999999929;
    temae_list =
     [("中野坂上", "東京"); ("新中野", "東京");
      ("東高円寺", "東京"); ("新高円寺", "東京");
      ("南阿佐ヶ谷", "東京"); ("荻窪", "東京")]};
   {namae = ("西新宿", "東京"); saitan_kyori = 6.79999999999999893;
    temae_list =
     [("西新宿", "東京"); ("中野坂上", "東京");
      ("新中野", "東京"); ("東高円寺", "東京");
      ("新高円寺", "東京"); ("南阿佐ヶ谷", "東京");
      ("荻窪", "東京")]};
   {namae = ("新宿", "東京"); saitan_kyori = 7.59999999999999876;
    temae_list =
     [("新宿", "東京"); ("西新宿", "東京");
      ("中野坂上", "東京"); ("新中野", "東京");
      ("東高円寺", "東京"); ("新高円寺", "東京");
      ("南阿佐ヶ谷", "東京"); ("荻窪", "東京")]}]

let test3=dijkstra_main [{namae = ("荻窪", "東京"); saitan_kyori = 0.;
    temae_list = [("荻窪", "東京")]};{namae = ("荻窪", "東京"); saitan_kyori = 0.;
                                          temae_list = [("荻窪", "東京")]}] local_ekikan_list
    = [{namae = ("荻窪", "東京"); saitan_kyori = 0.;
    temae_list = [("荻窪", "東京")]};
   {namae = ("荻窪", "東京"); saitan_kyori = 0.;
    temae_list = [("荻窪", "東京")]}]
(*
let test2=dijkstra_main global_eki_list global_ekikan_list*)
    
let test4 =dijkstra_main []  global_ekikan_list

= []



(* 目的：起点の（ローマ字の）駅名と終点の（ローマ字の）駅名 と駅名リスト（ekimei_t list 型）・ 駅間リスト（ekikan_t list 型） を受け取ったら、起点と終点の駅名ペアを求め、 受け取った駅名リストから 重複を取り除き、 駅のリスト（eki_t list 型）を作り、 各駅までの最短路を確定し、 その中から終点の駅（eki_t 型）を探して返す *)
(* dijkstra : string -> string -> ekimei_t list -> ekikan_t list -> eki_t *)

let dijkstra start goal ekimeilst ekikanlst =
  let startpair=romaji_to_kanji2 start ekimeilst
  in let ekilist =
       shokika2 (make_eki_list2 (seiretsu2 ekimeilst)) startpair
  in let goal=romaji_to_kanji2 goal ekimeilst
  in let shortlist=dijkstra_main ekilist ekikanlst
  in let searcheki namae lst =
        let string data=match data with {namae=n}->n=namae 
        in List. filter (string) lst
  in searcheki goal shortlist

let test1=dijkstra "ogikubo" "shinjuku" local_ekimei_list local_ekikan_list
    = [{namae = ("新宿", "東京"); saitan_kyori = 7.59999999999999876;
    temae_list =
     [("新宿", "東京"); ("西新宿", "東京");
      ("中野坂上", "東京"); ("新中野", "東京");
      ("東高円寺", "東京"); ("新高円寺", "東京");
      ("南阿佐ヶ谷", "東京"); ("荻窪", "東京")]}]
    
let test2=dijkstra "ogikubo" "myogadani" global_ekimei_list global_ekikan_list
    = [{namae = ("茗荷谷", "東京"); saitan_kyori = 15.7999999999999989;
    temae_list =
     [("茗荷谷", "東京"); ("後楽園", "東京");
      ("飯田橋", "東京"); ("市ヶ谷", "東京");
      ("四ツ谷", "東京"); ("四谷三丁目", "東京");
      ("新宿御苑前", "東京"); ("新宿三丁目", "東京");
      ("新宿", "東京"); ("西新宿", "東京");
      ("中野坂上", "東京"); ("新中野", "東京");
      ("東高円寺", "東京"); ("新高円寺", "東京");
      ("南阿佐ヶ谷", "東京"); ("荻窪", "東京")]}]

let test3=dijkstra "ogikubo" "yama" local_ekimei_list local_ekikan_list
=[]

let test4= dijkstra "ogikubo" "ogikubo" local_ekimei_list local_ekikan_list

#use "metro.ml"
type eki_t = {
  namae : string*string;(*駅名と県名*)
  saitan_kyori : float;(*最短距離*)
  temae_list : (string*string) list;(*駅名ペアのリスト*)
}

(* get_ekikan_kyori2  : string*string -> string*string -> ekikan_t -> float *)
let rec get_ekikan_kyori2  p1 p2 ekikan_t = match ekikan_t with
    []->infinity
  |first::rest->match (p1,p2) with
      ((a,b),(c,d))->match first with
        {kiten=kiten; kenk=kenk; shuten=shuten; kens=kens; keiyu=keiyu; kyori=kyori}->
        if (a=kiten && b=kenk && c=shuten && d=kens) || (a=shuten && b=kens && c=kiten && d=kenk) then kyori
        else get_ekikan_kyori2 p1 p2 rest
            
let rec saitan_wo_bunri2 list = match list with
    []->({namae=("",""); saitan_kyori=infinity; temae_list=[]},[])
  |first::rest->match first with
      {saitan_kyori=s1}->

      let (a,b) = saitan_wo_bunri2 rest in match a with

        {saitan_kyori=s2}->
        if a = {namae=("",""); saitan_kyori=infinity; temae_list=[]} then (first,[])
        else if s1<s2 then (first,rest)
        else (a,first::b)

let koushin1 p q list =match p with
    {namae=pnamae; saitan_kyori=pkyori; temae_list=ptemae}->match q with
      {namae=qnamae; saitan_kyori=qkyori; temae_list=qtemae}->
      let pqkyori=  get_ekikan_kyori2 pnamae qnamae list in
      if pqkyori=infinity then q
      else if pkyori+.pqkyori < qkyori then {namae=qnamae; saitan_kyori=pkyori+.pqkyori; temae_list=qnamae::ptemae}
      else q

let koushin  p v list =
  let koushin2 q =  koushin1 p q list
      in List.map koushin2 v


(* 目的：起点のみ最短距離が 0 で他は infinity となっている 駅のリスト（eki_t list 型） と駅間リスト（ekikan_t list 型） を受け取ったら、「起点からの最短距離と『起点からその駅に至る 駅名の（逆順の）リスト』が入った駅」のリスト（eki_t list 型）を返す  *)
(* dijkstra_main : eki_t list -> ekikan_t list -> eki_t list *)

let rec dijkstra_main eki ekikan =match eki  with
    []->[]
  |first::rest->match (saitan_wo_bunri2 eki) with
    (x,y)->x::dijkstra_main (koushin x y ekikan) ekikan
  
  
  (* テスト *)

let eki_t_list =  [ {namae=("根津","東京");saitan_kyori=0.;temae_list=[("根津","東京")]};{namae=("千駄木","東京");saitan_kyori=infinity;temae_list=[]};{namae=("西日暮里","東京");saitan_kyori=infinity;temae_list=[]}]
  let ekikan_list = [{kiten="根津"; kenk="東京"; shuten="千駄木"; kens="東京"; keiyu="千代田線"; kyori=1.0; jikan=2};
{kiten="千駄木"; kenk="東京"; shuten="西日暮里"; kens="東京"; keiyu="千代田線"; kyori=0.9; jikan=1};
{kiten="西日暮里"; kenk="東京"; shuten="町屋"; kens="東京"; keiyu="千代田線"; kyori=1.7; jikan=2};
{kiten="町屋"; kenk="東京"; shuten="北千住"; kens="東京"; keiyu="千代田線"; kyori=2.6; jikan=3};
                     {kiten="北千住"; kenk="東京"; shuten="綾瀬"; kens="東京"; keiyu="千代田線"; kyori=2.5; jikan=3}]

let test1 = dijkstra_main eki_t_list ekikan_list = [{namae = ("根津", "東京"); saitan_kyori = 0.; temae_list = [("根津", "東京")]};{namae = ("千駄木", "東京"); saitan_kyori = 1.;temae_list = [("千駄木", "東京"); ("根津", "東京")]};{namae = ("西日暮里", "東京"); saitan_kyori = 1.9;temae_list =[("西日暮里", "東京"); ("千駄木", "東京");("根津", "東京")]}]
(*let test2 = dijkstra_main   = 
    let test3 = dijkstra_main   = *)

(*問３*)
(* romaji_to_kanji2 : string -> ekimei_t -> string*string *)
let rec romaji_to_kanji2 r ekimei_t = match ekimei_t with
  []->("","")
  | first::rest ->match first with
    {kanji=kj;kana=k;romaji=rom;ken=ken;shozoku=s}-> if r=rom then (kj,ken)
    else romaji_to_kanji2 r rest;;

let rec insert2 lst m = match lst with
    []->[m]
  |first::rest->match first with
      {kanji=kanji; ken=ken}-> match m with
        {kanji=kj; ken=k}->if k<ken then m::first::rest
        else if k>ken then first::insert2 rest m
        else if kj<kanji then m::first::rest
        else if kj>kanji then first::insert2 rest m
                  else first::rest             
                             

(* 目的：ekimei_list を受け取ったら、それを上に述べた順に整列し、 さらに重複した駅を取り除いた ekimei_list を返す *)
(* seiretsu2 : ekimei_list -> ekimei_t list *)
let rec seiretsu2 ekimei_t=match ekimei_t with
      []->[]
  |first::rest-> insert2 (seiretsu2 rest) first
                   
(* make_eki_list2 : ekimei_t list -> eki_t list *)
let rec make_eki_list2 ekimei_list = match ekimei_list with
    []->[]
  |first::rest->match first with
      {kanji=kanji; ken=ken}->{namae=(kanji,ken); saitan_kyori=infinity;temae_list= []}::(make_eki_list2 rest)

(* shokika2 : eki_t list -> string*string -> eki_t list *)
let rec shokika2 eki_t_list pair = match eki_t_list with
      []->[]
    |first::rest->match first with

        {namae=n; saitan_kyori=s; temae_list=t}-> if pair = n then {namae=pair; saitan_kyori=0.; temae_list=[pair] }::(shokika2 rest pair)
        else first::(shokika2 rest pair)

(* 目的：終点の駅（eki_t 型）を探して返す *)
(* research_shuten : string*string -> eki_t_list -> eki_t *)
let rec research_shuten shuten_pair new_eki_t_list
 = match new_eki_t_list with
    []->{namae=("","");saitan_kyori=infinity;temae_list=[]}
  |first::rest->match first with
      {namae=namae;saitan_kyori=saitan_kyori;temae_list=temae_list}->
      if namae = shuten_pair then first
        else research_shuten shuten_pair rest
    
             

 (* 目的：起点の（ローマ字の）駅名と終点の（ローマ字の）駅名 と駅名リスト（ekimei_t list 型）・ 駅間リスト（ekikan_t list 型） を受け取ったら、終点の駅（eki_t 型）を探して返す *)
(* 関数名 : string -> string -> ekimei_t list -> ekikan_t list -> eki_t *)
let rec dijkstra kiten shuten ekimei_list ekikan_list =
  
  let kiten_pair = romaji_to_kanji2 kiten ekimei_list in 
let shuten_pair = romaji_to_kanji2 shuten ekimei_list in

let seiretsu_ekimei_list = seiretsu2 ekimei_list in 

let eki_t_list = shokika2 (make_eki_list2 seiretsu_ekimei_list) kiten_pair
in
let new_eki_t_list = dijkstra_main eki_t_list ekikan_list
in
research_shuten shuten_pair new_eki_t_list

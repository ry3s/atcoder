let rec calc x =
  if x mod 2 = 0 then 1 + calc (x / 2) else 0
let () =
  Scanf.scanf "%d" (fun n ->
      Array.init n (fun _ -> Scanf.scanf " %d" (fun x -> x )))
  |> Array.map calc
  |> Array.fold_left min 100
  |> Printf.printf "%d\n"

(* let rec calc x = (\* xを奇数にするために何回2で割る必要があるかを求めている *\)
 *   if x mod 2 = 0 then 1 + calc (x / 2) else 0
 * let () =
 *   Scanf.scanf "%d" (fun n ->
 *     List.init n (fun _ -> Scanf.scanf " %d" (fun x -> x)))
 *   |> List.map calc (\* 各要素にcalcを適用 *\)
 *   |> List.fold_left min 100 (\* 最小値を求める (100 は適当に大きな数) *\)
 *   |> Printf.printf "%d\n" *)

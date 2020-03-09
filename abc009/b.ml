let list_unique lst =
  let rec list_unique_aux l acc =
    match l with
    | [] -> acc
    | x :: xs -> if List.exists (fun e -> e = x) acc
                 then list_unique_aux xs acc
                 else list_unique_aux xs (acc @ [x])
  in list_unique_aux lst []

let n = Scanf.scanf " %d" (fun x -> x)
let arr = Array.init n @@ fun _ -> Scanf.scanf " %d" (fun x -> x)
let lst = Array.to_list arr
let () =
  let lst = List.sort compare lst in
  let lst' = list_unique lst in
  let lst' = List.rev lst' in
  Printf.printf "%d\n" (List.nth lst' 1)

let rec f x =
  if x mod 2 = 0 then
    1 + f (x/2)
  else
    0
let () =
  let n = Scanf.scanf "%d" (fun x -> x) in
  let ss = Array.init n (fun _ -> Scanf.scanf " %d" (fun x -> x)) in
  Array.to_list ss
  |> List.filter (fun x -> x mod 2 = 0)
  |> List.map (fun x -> f x)
  |> List.sort compare
  |> List.fold_left (+) 0
  |> Printf.printf "%d\n"


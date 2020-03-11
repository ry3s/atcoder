let n, k = Scanf.scanf " %d %d" (fun x y -> (x, y))
let arr = Array.init n @@ fun _ -> (Scanf.scanf " %d" (fun x -> x))

let () =
  let r = 2.0 ** float (k - 1) in
  Array.to_list arr
  |> List.sort compare
  |> List.rev
  |> List.fold_left (fun (i, r, acc) x ->
         if i = 0 then (0, r, acc)
         else (i - 1, r /. 2.0, acc +. r *. float x)
       ) (k, r, 0.)
  |> (fun (_, _, acc) -> acc /. (r *. 2.0))
  |> Printf.printf "%f\n"

let rec list_init n f =
  if n <= 0 then [] else let x = f () in x :: list_init (n-1) f
;;
let () =
  Scanf.scanf "%d" (fun n ->
      list_init n (fun _ -> Scanf.scanf " %d" (fun x -> x ))) 
  |> List.sort (-)
  |> List.rev
  |> List.fold_left (fun (a, s) e -> (a + s * e, -s)) (0, +1)
  |> fst
  |> Printf.printf "%d\n"
       

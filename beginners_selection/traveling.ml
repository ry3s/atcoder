let () =
  Scanf.scanf "%d " (fun n ->
      Array.init n (fun _ -> Scanf.scanf " %d %d %d" (fun x y z -> x, y, z)))
      |> Array.fold_left (fun (ans, (t1, x1, y1)) (t2, x2, y2) ->
             let d = abs (x1-x2) + abs (y1-y2) in
             let ans' = ans
                        && t2-t1 >= d
                        && (t2-t1-d) mod 2 = 0 in
             (ans', (t2, x2, y2))) (true, (0, 0, 0))
      |> (fun (ans, _) -> if ans then "Yes" else "No")
      |> Printf.printf "%s\n"
           

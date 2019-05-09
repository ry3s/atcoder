let () =
  let n = Scanf.scanf "%d\n" (fun x -> x) in
  let ax = Array.init n (fun _ ->
               Scanf.scanf " %d" (fun x -> x)) in
   let res = Array.fold_left (fun res x ->
                res + x - 1
              ) 0 ax in
  
  Printf.printf "%d\n" res
  


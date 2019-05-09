let () =
  let n, m, x = Scanf.scanf "%d %d %d" (fun n m x -> n, m, x) in
  let a = Array.init m (fun _ -> Scanf.scanf " %d" (fun x -> x)) in
  let (l, r) =  Array.fold_left (fun (l, r) ai  -> if ai < x then (l+1, r) else (l, r+1)) (0,0)  a in
  Printf.printf "%d\n" (if r < l then r else l) 
 

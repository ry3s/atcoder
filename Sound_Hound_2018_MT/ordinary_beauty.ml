let () =
  let n, m, d = Scanf.scanf "%d %d %d" (fun n m d -> n, m, d) in
  (if d = 0 then
     1.0 /. float n *. float (m-1)
   else
     2.0 *. float (n - d) /. float (n * n) *. float (m-1))
  |> Printf.printf "%.7f\n" 
  


                            
    

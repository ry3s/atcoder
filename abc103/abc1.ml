let () =
  let lst = Scanf.scanf "%d %d %d\n"
                    (fun x y z-> [x; y; z]) in
  let [a;b;c] =  (List.sort (-) lst) in
  Printf.printf "%d\n" ((b-a) + (c-b))
                                  
      

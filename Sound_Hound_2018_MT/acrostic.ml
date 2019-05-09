let () =
  let res = ref [] in
  let s = Scanf.scanf "%s\n" (fun x -> x) in
  let w = Scanf.scanf "%d\n" (fun x -> x) in
  for i = 0 to (String.length s) -1 do
    if i mod w = 0 then
      res := !res @ [s.[i]]
    else
      ()
  done;
  List.iter (Printf.printf "%c") !res;
  Printf.printf "\n"
  
    
               
  

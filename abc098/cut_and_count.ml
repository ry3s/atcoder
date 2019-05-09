let base = int_of_char 'a'
let () =
  Scanf.scanf "%d " @@ fun n  -> 
  let s =  Array.init n (fun _ ->
               Scanf.scanf "%c" (fun x -> x)) in
  let result = ref 0 in
  for i = 0 to (n-1) do
    let left = Array.sub s 0 i in
    let right = Array.sub s i (n-i)  in
    let left' = Array.to_list left in
    let right' = Array.to_list right in
    let num = ref 0 in
    for i = 0 to 26 do
      if List.mem (char_of_int (i+base)) left' = true
         && List.mem (char_of_int (i+base)) right' = true then
        num := 1 + !num
      else
        ()
    done;
    if !num > !result then result := !num
    else ()
  done;
  Printf.printf "%d\n" (!result)

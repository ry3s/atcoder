let split_string s = Str.split (Str.regexp "") s
let () =
  let res = ref "No" in
  let f lst =
    match lst with
    | x :: xs -> xs @ [x] in
  let s = split_string @@ Scanf.scanf "%s\n" (fun x -> x) in
  let t = split_string @@ Scanf.scanf "%s\n" (fun x -> x) in
  let x = ref t in
  for i = 0 to List.length s do
    (x := f (!x);
     if compare s !x = 0 then res := "Yes"
     else ()
    )
  done;
  
  Printf.printf "%s\n" !res


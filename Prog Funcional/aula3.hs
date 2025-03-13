main = do --Monad
   putStrLn "HW"
   putStrLn $ show $ sinal 10
   putStrLn $ show $ somaPos lista
   
   -- Lendo linhas (não compila aqui só pq é online?)
   la <- getLine -- usa seta <- pois getLine é impura
   let a = read la  -- read faz o "inverso" de show, tranforma string em tipos
   lb <- getLine
   let b = read lb
   lc <- getLine -- exemplo de usar uma função impura
   let c = read lc  -- exemplo de usar uma função pura
   
   let res = baskara a b c
   putStrLn $ show $ res

sinal x 
  | x < 0 = -1
  | x == 0 = 0
  | otherwise = 1 -- teria o mesmo efeito que substituir por "True = 1"

absoluto x
  | x >= 0= x
  | otherwise = -x
  
-- Soma dos positivos de uma lista
somaPos [] = 0
somaPos (x:xs)
  | x > 0 = x + somaPos xs
  | otherwise = somaPos xs
  
lista = [10, -3, 0, -5, 4]

-- Baskara
baskara a b c
  | delta < 0 = []
  | delta == 0 = [x]
  | otherwise = [x', x'']
    where
      delta = b ^ 2 - 4 * a * c
      x = (-b) / (2*a)
      x' = (-b + sqrt delta) / (2*a)
      x'' = (-b - sqrt delta) / (2*a)
      

     
     
     
     
     
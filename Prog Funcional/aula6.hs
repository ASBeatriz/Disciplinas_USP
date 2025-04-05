main = do
    putStrLn "HW"
    -- putStrLn $ show $ primos    -- imprime todos os primos
    putStrLn $ show $ pega 10 primos  -- imprime os 10 primeiros primos
    putStrLn $ show $ pega 10 primos'  
    putStrLn $ show $ pega 10 primos''  
    putStrLn $ show $ pegaEqto (<100) primos -- imprime os primos menores do que 100
    putStrLn $ show $ pega 10 $ ignoraEqto (<1000) primos -- imprime os 10 primeiros primos maiores que 10000
    putStrLn $ show $ soma $ pegaEqto (<200) $ ignoraEqto (<100) primos -- imprime a soma dos primos entre 100 e 200

    putStrLn $ show $ zipa [1, 2, 3, 4, 5, 6, 7] "Beatriz"  -- zipa as duas listas
    putStrLn $ show $ pega 10 $ zipa [1..] primos  -- zipa as duas listas (imprime os primos e suas posições)

    -- imprimir a posição do primeiro primo maior do que 1000
    putStrLn $ show $ segundo $ head $ ignoraEqto ((<1000).primeiro) $ zipa primos [1..]

    putStrLn $ show $ pega 10 $ zipaCom (+) primos uns  -- adiciona 1 nos primos
    putStrLn $ show $ zipaCom (^) [2, 3, 5, 4] [0, 1, 2, 3]

-- Crivo de eratóstenes: método para encontrar os números primos. Pega o primeiro elemento (crivo) e elimina seus múltiplos... repete o processo até acabar (nesse caso, a lista é infinita)
-- Todos os números primos:
primos = crivo [2..]
    where 
        crivo (x:xs) = x: (crivo $ filtra (naoEhMultiplo x) xs)


-- Usando Curry:
primos' =  crivo [2..]
    where
        crivo (x:xs) = x:(crivo $ filtra (\y -> y `mod` x /= 0) xs)

-- Dá para melhorar. Podemos usar a função '.' para combinar duas funções, por exemplo: f.g x = f(g x), tal qual função
-- composta na matamética! 
primos'' = crivo [2..]
    where
        crivo (x:xs) = x:(crivo $ filtra ((/= 0).(`mod` x)) xs) -- ou seja, primeiro o mod é aplicado e depois a comparação

-- Se fossemos definir a função '.', seria algo assim:
--  (.) :: (b -> c) -> (a -> b) -> (a -> c)

naoEhMultiplo :: Integer -> Integer -> Bool
naoEhMultiplo x y = y `mod` x /= 0
 
-- Função para filtrar os elementos de uma lista
filtra :: (a -> Bool) -> [a] -> [a]
filtra _ [] = []
filtra t (x:xs)
    | t x = x:filtra t xs
    | otherwise = filtra t xs

-- Função para pegar n elementos de uma lista
pega _ [] = []
pega 0 _ = []
pega n (x:xs) = x:pega (n-1) xs

-- pega os elementos da lista enquanto satisfazem a condição
pegaEqto :: (a -> Bool) -> [a] -> [a]   
pegaEqto _ [] = []
pegaEqto t (x:xs)
    | t x = x: pegaEqto t xs
    | otherwise = []

-- ignora os elementos da lista enquanto satisfazem a condição
ignoraEqto :: (a -> Bool) -> [a] -> [a]   
ignoraEqto _ [] = []
ignoraEqto t (x:xs)
    | t x = ignoraEqto t xs
    | otherwise = x:xs

-- soma elemetos de uma lista
soma [] = 0
soma (x:xs) = x + soma xs

-- zipa: associa os elementos correspondentes de duas listas (cria tuplas)
zipa :: [a] -> [b] -> [(a,b)]
zipa [] _ = []
zipa _ [] = []
zipa (x:xs) (y:ys) = (x,y):zipa xs ys

-- Função que retona o primeiro elemento de uma tupla
primeiro :: (a, b) -> a
primeiro (x,_) = x

-- Função que retona o segundo elemento de uma tupla
segundo :: (a, b) -> b
segundo (_, x) = x

-- Versão zipa genérico, passaremos a operação que queremos realizar como parametro
zipaCom op _ [] = []
zipaCom op [] _ = []
zipaCom op (x:xs) (y:ys) = (op x y): zipaCom op xs ys 

-- Lista infinita de 1's
uns = 1:uns
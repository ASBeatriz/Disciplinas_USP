main = do -- Monad
   putStrLn "Hello World!"
   --- putStrLn x -- da erro
   putStrLn (show z)
   putStrLn $ show a
   putStrLn $ show $ f True
   putStrLn $ show $ f $ y < 2
   -- putStrLn $ show $ x -- da problema
   putStrLn $ show $ g x -- n dá problema pq n usa o x
   putStrLn $ show $ g 100
   putStrLn $ show $ k 15
   putStrLn $ show $ h 20 False
   putStrLn $ show $ h1 20 True
   putStrLn $ show $ fat 10
   putStrLn $ show $ p o3
   putStrLn $ show $ head o3
   putStrLn $ show $ tail o3
   -- putStrLn $ show $ t o3 -- pq n funciona??

-- A ordem das definições não é relevante, pois estamos definindo e não calculando

-- Numéricos
x = x + 1
z = y + 1
y = 6

-- Booleanos
a = True
b = False
c = 5 > y

-- Funções
f True = 10  -- f aplicado em True dá 10
f False = 42

g t = 57 -- Função constante
k x = x + 100

h x False = x - 1
h x True = x + 1

h1 x b = if b
           then x + 1
           else x - 1
           
fat 0 = 1
fat x = x * fat(x - 1)

-- Listas 
o1 = []
o2 = [5]
o3 = [6, 42, y, fat 5, h 8 True]
-- o4 = [3, "oi", True] -- Não Funciona
o5 = 7:o2 -- concatenação

-- Função com lista
p [] = 0
p [x] = 1
p  l = 2

t [] = 0
t (x:xs) = 1 + k xs -- retorna o tamanho da lista (?)
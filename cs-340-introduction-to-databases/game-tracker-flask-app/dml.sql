---------------
--Users page--
---------------

-- get all user records
select id, name, email from user

-- get one user record
SELECT id, name, email from user WHERE id = %s

-- update user record
UPDATE user SET name = %s, email = %s WHERE id = %s

-- delete user record
DELETE FROM user WHERE id = %s

-- create user record
INSERT INTO user (name, email) VALUES (%s,%s)


-- search for users
select id, name, email from user where name like '%{0}%' or email like  '%{1}%'

----------------
--Games page--
----------------

-- create game
INSERT INTO game (name, developer, genre, platform) VALUES (%s,%s,%s,%s)

-- get all games
select 
id, 
name, 
developer,
platform,
genre 
from game

-- get individual game by id
select
id,
name,
developer,
platform,
genre
from game where id = %s

--search games by user entered criteria
select 
id, 
name, 
developer,
platform,
genre 
from games
where name like '%{0}%' or developer like '%{1}%' or platform like '%{2}%' or genre like '%{3}%'


--remove game
delete from game where id = :id_input


--update game
update game set name = :name_in, genre = :genre_in, platform = :platform_in, developer = :developer_in where id = :id_in


------------------
--Favorites page--
------------------

-- create favorite
INSERT INTO userFavoriteGame (user_id, game_id, rating, rating_comment) VALUES (%s,%s,%s,%s)


-- get all favorites
select 
user.name,
game.name,
userFavoriteGame.rating,
userFavoriteGame.rating_comment
from game
join userFavoriteGame on game.id = userFavoriteGame.game_id
join user on userFavoriteGame.user_id = user.id


-- retrieve one favorite
SELECT id, rating, rating_comment from userFavoriteGame WHERE id = %s

--delete favorite
delete from userFavoriteGame where id = :id_in

--update favorite
update userFavoriteGame set rating = :rating_in, rating_comment = :rating_comment_in where id = :id_in

-- search favorites
SELECT userFavoriteGame.id, user.name, game.name, rating, rating_comment 
from userFavoriteGame join user on userFavoriteGame.user_id = user.id join game on userFavoriteGame.game_id = game.id 
where user.name like '%{0}%' or game.name like '%{1}%' or user.email like '%{2}%'


-----------------
--Session page--
-----------------

--create session
insert into gameSession (`user_id`,`game_id`,`started_at`,`ended_at`) values (:user_id_in, :game_id_in, :started_at_in, :ended_at_in)

--retrieve all game sessions
SELECT userFavoriteGame.id, user.name, game.name, rating, rating_comment 
from userFavoriteGame join user on userFavoriteGame.user_id = user.id join game on userFavoriteGame.game_id = game.id

-- retrieve one game session
select gameSession.id, name, started_at, ended_at from gameSession join game on gameSession.game_id = game.id where gameSession.id = %s

-- search search game sessions
SELECT userFavoriteGame.id, user.name, game.name, rating, rating_comment 
from userFavoriteGame join user on userFavoriteGame.user_id = user.id join game on userFavoriteGame.game_id = game.id 
where user.name like '%{0}%' or game.name like '%{1}%' or user.email like '%{2}%'

--delete game session
delete from gameSession where id = :id_in


-- update game session
UPDATE gameSession SET started_at = %s, ended_at = %s WHERE id = %s




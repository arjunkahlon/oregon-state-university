-- create the tables

create table `game` (

    `id` int unsigned NOT NULL AUTO_INCREMENT,
    `name` varchar(255) NOT NULL,
    `developer` varchar(255) NOT NULL,
    `genre` varchar(255) NOT NULL,
    `platform` varchar(255) NOT NULL,
    PRIMARY KEY(`id`),
    KEY `idx_name` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


create table `user` (

    `id` int unsigned NOT NULL AUTO_INCREMENT,
    `name` varchar(255) NOT NULL,
    `email` varchar(255),         
    PRIMARY KEY (`id`),
    KEY `idx_name` (`name`)

) ENGINE=InnoDB DEFAULT CHARSET=utf8;


create table `userFavoriteGame` (

    `id` int unsigned NOT NULL AUTO_INCREMENT,
    `user_id` int unsigned NOT NULL,
    `game_id` int unsigned NOT NULL,
    `rating` float,
    `rating_comment` varchar(8000),
    PRIMARY KEY(`id`),
    KEY `idx_user_id` (`user_id`),
    KEY `idx_game_id` (`game_id`),
    CONSTRAINT `fk_user_id` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`) ON UPDATE CASCADE,
    CONSTRAINT `fk_game_id` FOREIGN KEY (`game_id`) REFERENCES `game` (`id`) ON UPDATE CASCADE

) ENGINE=InnoDB DEFAULT CHARSET=utf8;


create table `gameSession` (

    `id` int unsigned NOT NULL AUTO_INCREMENT,
    `user_id` int unsigned NOT NULL,
    `game_id` int unsigned NOT NULL,
    `started_at` datetime,
    `ended_at` datetime,
     PRIMARY KEY(`id`),
     KEY `idx_user_id` (`user_id`),
     KEY `idx_game_id` (`game_id`),
    CONSTRAINT `fk_session_user_id` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`) ON UPDATE CASCADE,
    CONSTRAINT `fk_session_game_id` FOREIGN KEY (`game_id`) REFERENCES `game` (`id`) ON UPDATE CASCADE
    
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


-- populate sample data
insert into `game` (`name`, `developer`, `genre`, `platform`) 
values ('donkey kong country', 'nintendo', 'action', 'super nintendo'),
('Grand Theft Auto 5', 'rockstar games', 'action-adventure', 'PlayStation 4');



insert into `user` (`name`, `email`) values
('john doe', 'jdoe@example.com'),
('jane smith', 'jsmith@example.com');


insert into `userFavoriteGame` (`user_id`, `game_id`, `rating`,`rating_comment`) values
(1, 2, 4.5, 'I love the gritty story lines.'),
(2,1, 3.7,  'Interesting level design, but the gameplay becomes repetitive');

insert into `gameSession` (`user_id`, `game_id`, `started_at`, `ended_at`) values (1, 2, '2019-11-5T08:03:11', '2019-11-5T09:45:58');
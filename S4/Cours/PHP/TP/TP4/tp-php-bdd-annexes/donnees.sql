-- phpMyAdmin SQL Dump
-- version 4.7.6
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le :  jeu. 22 mars 2018 à 08:51
-- Version du serveur :  5.7.20
-- Version de PHP :  7.1.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `l2_tp_sportifs`
--

--
-- Déchargement des données de la table `personne`
--

INSERT INTO `personne` (`id_personne`, `nom`, `prenom`, `depart`, `mail`) VALUES
(1, 'Bart', 'Jean', 59, 'jean.bart@en.guerre'),
(2, 'Surcouf', 'Robert', 66, 'surcouf@catch.me'),
(3, 'Azerty', '', 13, 'azerty@no.clue'),
(4, 'Do', 'You', 84, 'know@what'),
(5, 'Anywhere', 'Out', 99, 'of@the.world'),
(7, 'Jacques', '', 49, 'jacques@a.dit'),
(8, 'Mel', 'E', 49, 'm.a@i.l'),
(9, 'Loeb', 'Sébastien', 67, 'loeb@mille.lacs');

--
-- Déchargement des données de la table `pratique`
--

INSERT INTO `pratique` (`id_personne`, `id_sport`, `niveau`) VALUES
(2, 2, 3),
(2, 3, 3),
(4, 2, 3);

--
-- Déchargement des données de la table `sport`
--

INSERT INTO `sport` (`id_sport`, `design`) VALUES
(1, 'Badminton'),
(2, 'Tennis'),
(3, 'Tennis de table'),
(4, 'Volley-Ball'),
(5, 'Handball'),
(6, 'Football');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

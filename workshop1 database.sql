-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 23, 2023 at 10:41 PM
-- Server version: 10.4.27-MariaDB
-- PHP Version: 8.2.0

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `workshop1`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `admin_id` varchar(10) NOT NULL,
  `adminPassword` varchar(8) DEFAULT NULL,
  `adminName` varchar(50) DEFAULT NULL,
  `adminPhoneNo` varchar(11) DEFAULT NULL,
  `adminEmail` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`admin_id`, `adminPassword`, `adminName`, `adminPhoneNo`, `adminEmail`) VALUES
('adminA1', 'adminA01', 'CIK NUR ATIQA IDAYU', '01112110395', 'atiqaidayu@gmail.com'),
('adminB1', 'adminB01', 'EN. MOHD AMSYAR HUZAIFY', '0192892124', 'amsyarhuzaify@gmail.com');

-- --------------------------------------------------------

--
-- Table structure for table `appliance_registration`
--

CREATE TABLE `appliance_registration` (
  `registerId` int(7) NOT NULL,
  `applianceCode` varchar(4) NOT NULL,
  `appRegDate` date NOT NULL,
  `matricNo` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `appliance_registration`
--

INSERT INTO `appliance_registration` (`registerId`, `applianceCode`, `appRegDate`, `matricNo`) VALUES
(1000004, 'EX00', '2023-01-18', 'B032110255'),
(1000005, 'IR00', '2023-01-18', 'B032110255'),
(1000006, 'EX00', '2023-01-18', 'B032110255'),
(1000007, 'IR00', '2023-01-18', 'B032110255'),
(1000008, 'EX00', '2023-01-18', 'B032110255'),
(1000021, 'EX00', '2023-01-18', 'B032110197'),
(1000022, 'IR00', '2023-01-18', 'B032110197'),
(1000023, 'TF00', '2023-01-18', 'B032110197'),
(1000025, 'EX00', '2023-01-18', 'B032116767'),
(1000026, 'IR00', '2023-01-18', 'B032116767'),
(1000027, 'EX00', '2023-01-20', 'B032110255'),
(1000028, 'TF00', '2023-01-20', 'B032110255'),
(1000046, 'EX00', '2023-01-20', 'B032110191'),
(1000048, 'WH00', '2023-01-20', 'B032110191'),
(1000049, 'EX00', '2023-01-20', 'B032110191');

-- --------------------------------------------------------

--
-- Table structure for table `electrical_appliance`
--

CREATE TABLE `electrical_appliance` (
  `applianceCode` varchar(4) NOT NULL,
  `applianceType` varchar(30) NOT NULL,
  `applianceCharge` decimal(10,2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `electrical_appliance`
--

INSERT INTO `electrical_appliance` (`applianceCode`, `applianceType`, `applianceCharge`) VALUES
('EX00', 'EXTENSION PLUG', '12.00'),
('IR00', 'IRON', '5.00'),
('TF00', 'TABLE FAN', '15.00'),
('TR00', 'TOASTER', '15.00'),
('WH00', 'WATER HEATER', '10.00');

-- --------------------------------------------------------

--
-- Table structure for table `faculty`
--

CREATE TABLE `faculty` (
  `facultyCode` varchar(5) NOT NULL,
  `facultyName` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `faculty`
--

INSERT INTO `faculty` (`facultyCode`, `facultyName`) VALUES
('FKE', 'Fakulti Kejuruteraan Elektrik'),
('FKEKK', 'Fakulti Kejuruteraan Elektronik Dan Komputer'),
('FKM', 'Fakulti Kejuruteraan Mekanikal'),
('FKP', 'Fakulti Kejuruteraan Pembuatan'),
('FPTT', 'Fakulti Pengurusan Teknologi Dan Teknousahawanan'),
('FTKEE', 'Fakulti Teknologi Kejuruteraan Elektrikal dan Elektronik'),
('FTKMP', 'Fakulti Kejuruteraan Mekanikal dan Pembuatan'),
('FTMK', 'Fakulti Teknologi Maklumat Dan Komunikasi');

-- --------------------------------------------------------

--
-- Table structure for table `item_report`
--

CREATE TABLE `item_report` (
  `reportId` int(6) NOT NULL,
  `admin_id` varchar(10) NOT NULL,
  `roomNo` varchar(10) NOT NULL,
  `itemId` int(11) NOT NULL,
  `description` varchar(30) NOT NULL,
  `reportDate` date NOT NULL,
  `status` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `item_report`
--

INSERT INTO `item_report` (`reportId`, `admin_id`, `roomNo`, `itemId`, `description`, `reportDate`, `status`) VALUES
(100008, 'adminA1', 'A-01-07', 10090, 'BROKEN', '2023-01-18', 'FINISHED'),
(100009, 'adminA1', 'A-01-07', 10089, 'NOT FUNCTIONING', '2023-01-18', 'New!'),
(100012, 'adminA1', 'A-01-02', 10020, 'Broken', '2023-01-20', 'New!'),
(100013, 'adminA1', 'A-01-09', 10098, 'NOT FUNCTIONING', '2023-01-20', 'FINISHED'),
(100014, 'adminA1', 'A-01-09', 10098, 'NOT FUNCTIONING', '2023-01-20', 'New!'),
(100015, 'adminA1', 'A-01-09', 10096, 'BROKEN', '2023-01-20', 'New!');

-- --------------------------------------------------------

--
-- Table structure for table `room`
--

CREATE TABLE `room` (
  `roomNo` varchar(10) NOT NULL,
  `block` varchar(1) NOT NULL,
  `level` int(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `room`
--

INSERT INTO `room` (`roomNo`, `block`, `level`) VALUES
('A-01-01', 'A', 1),
('A-01-02', 'A', 1),
('A-01-03', 'A', 1),
('A-01-04', 'A', 1),
('A-01-05', 'A', 1),
('A-01-06', 'A', 1),
('A-01-07', 'A', 1),
('A-01-08', 'A', 1),
('A-01-09', 'A', 1),
('A-01-10', 'A', 1),
('A-02-01', 'A', 1),
('A-02-02', 'A', 2),
('A-02-03', 'A', 2),
('A-02-04', 'A', 2),
('A-02-05', 'A', 2),
('A-02-06', 'A', 2),
('A-02-07', 'A', 2),
('A-02-08', 'A', 2),
('A-02-09', 'A', 2),
('A-02-10', 'A', 2),
('B-01-01', 'B', 1),
('B-01-02', 'B', 2),
('B-01-03', 'B', 1),
('B-01-04', 'B', 1),
('B-01-05', 'B', 1),
('B-01-06', 'B', 1),
('B-01-07', 'B', 1),
('B-01-08', 'B', 1),
('B-01-09', 'B', 1),
('B-01-10', 'B', 1),
('B-02-01', 'B', 1),
('B-02-02', 'B', 2),
('B-02-03', 'B', 2),
('B-02-04', 'B', 2),
('B-02-05', 'B', 2),
('B-02-06', 'B', 2),
('B-02-07', 'B', 2),
('B-02-08', 'B', 2),
('B-02-09', 'B', 2),
('B-02-10', 'B', 2);

-- --------------------------------------------------------

--
-- Table structure for table `room_item`
--

CREATE TABLE `room_item` (
  `itemId` int(11) NOT NULL,
  `roomNo` varchar(10) NOT NULL,
  `itemtype` varchar(30) NOT NULL,
  `itemQuantity` int(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `room_item`
--

INSERT INTO `room_item` (`itemId`, `roomNo`, `itemtype`, `itemQuantity`) VALUES
(10004, 'A-01-01', 'DESK', 2),
(10007, 'A-01-02', 'CHAIR', 1),
(10009, 'B-01-01', 'BED', 2),
(10012, 'A-01-01', 'LAMP', 2),
(10015, 'A-01-01', 'FAN', 1),
(10016, 'A-01-01', 'LOCKER', 2),
(10017, 'A-01-02', 'DESK', 2),
(10018, 'A-01-02', 'LAMP', 2),
(10019, 'A-01-02', 'FAN', 2),
(10020, 'A-01-02', 'LOCKER', 2),
(10021, 'B-01-01', 'DESK', 2),
(10022, 'B-01-01', 'LAMP', 2),
(10023, 'B-01-01', 'FAN', 2),
(10024, 'B-01-01', 'LOCKER', 2),
(10027, 'B-01-02', 'LAMP', 2),
(10028, 'B-01-02', 'FAN', 2),
(10029, 'B-01-02', 'DESK', 2),
(10030, 'B-01-02', 'LOCKER', 2),
(10031, 'A-01-03', 'DESK', 2),
(10032, 'A-01-03', 'LOCKER', 2),
(10033, 'A-01-03', 'LAMP', 2),
(10034, 'A-01-03', 'FAN', 2),
(10035, 'A-01-03', 'CHAIR', 2),
(10071, 'A-01-04', 'DESK', 1),
(10072, 'A-01-04', 'LOCKER', 2),
(10073, 'A-01-04', 'LAMP', 2),
(10074, 'A-01-04', 'FAN', 2),
(10075, 'A-01-04', 'CHAIR', 2),
(10076, 'A-01-05', 'DESK', 2),
(10077, 'A-01-05', 'LOCKER', 2),
(10078, 'A-01-05', 'LAMP', 2),
(10079, 'A-01-05', 'FAN', 2),
(10080, 'A-01-05', 'CHAIR', 2),
(10081, 'A-01-06', 'DESK', 2),
(10082, 'A-01-06', 'LOCKER', 2),
(10083, 'A-01-06', 'LAMP', 2),
(10084, 'A-01-06', 'FAN', 2),
(10085, 'A-01-06', 'CHAIR', 2),
(10086, 'A-01-07', 'DESK', 2),
(10087, 'A-01-07', 'LOCKER', 2),
(10088, 'A-01-07', 'LAMP', 2),
(10089, 'A-01-07', 'FAN', 1),
(10090, 'A-01-07', 'CHAIR', 2),
(10091, 'A-01-08', 'DESK', 2),
(10092, 'A-01-08', 'LOCKER', 2),
(10093, 'A-01-08', 'LAMP', 2),
(10094, 'A-01-08', 'FAN', 1),
(10095, 'A-01-08', 'CHAIR', 2),
(10096, 'A-01-09', 'DESK', 3),
(10098, 'A-01-09', 'LAMP', 2),
(10099, 'A-01-09', 'FAN', 2),
(10100, 'A-01-09', 'CHAIR', 2),
(10101, 'A-01-10', 'DESK', 2),
(10102, 'A-01-10', 'LOCKER', 2),
(10103, 'A-01-10', 'LAMP', 2),
(10104, 'A-01-10', 'FAN', 2),
(10105, 'A-01-10', 'CHAIR', 2),
(10106, 'A-02-01', 'DESK', 2),
(10107, 'A-02-01', '	LOCKER', 2),
(10108, 'A-02-01', 'LAMP', 2),
(10109, 'A-02-01', 'FAN', 2),
(10110, 'A-02-01', 'CHAIR', 2),
(10111, 'A-02-02', 'DESK', 2),
(10112, 'A-02-02', '	LOCKER', 2),
(10113, 'A-02-02', 'LAMP', 2),
(10114, 'A-02-02', 'FAN', 2),
(10115, 'A-02-02', 'CHAIR', 2),
(10116, 'A-02-03', 'DESK', 2),
(10117, 'A-02-03', '	LOCKER', 2),
(10118, 'A-02-03', 'LAMP', 2),
(10119, 'A-02-03', 'FAN', 2),
(10120, 'A-02-03', 'CHAIR', 2),
(10121, 'A-02-04', 'DESK', 2),
(10122, 'A-02-04', 'LOCKER', 2),
(10123, 'A-02-04', 'LAMP', 2),
(10124, 'A-02-04', 'FAN', 2),
(10125, 'A-02-04', 'CHAIR', 2),
(10126, 'A-02-05', 'DESK', 2),
(10127, 'A-02-05', 'LOCKER', 2),
(10128, 'A-02-05', 'LAMP', 2),
(10129, 'A-02-05', 'FAN', 2),
(10130, 'A-02-05', 'CHAIR', 2),
(10131, 'A-02-06', 'DESK', 2),
(10132, 'A-02-06', 'LOCKER', 2),
(10133, 'A-02-06', 'LAMP', 2),
(10134, 'A-02-06', 'FAN', 2),
(10135, 'A-02-06', 'CHAIR', 2),
(10136, 'A-02-07', 'DESK', 2),
(10137, 'A-02-07', 'LOCKER', 2),
(10138, 'A-02-07', 'LAMP', 2),
(10139, 'A-02-07', 'FAN', 2),
(10140, 'A-02-07', 'CHAIR', 2),
(10141, 'A-02-08', 'DESK', 2),
(10142, 'A-02-08', 'LOCKER', 2),
(10143, 'A-02-08', 'LAMP', 2),
(10144, 'A-02-08', 'FAN', 2),
(10145, 'A-02-08', 'CHAIR', 2),
(10146, 'A-02-09', 'DESK', 2),
(10147, 'A-02-09', 'LOCKER', 2),
(10148, 'A-02-09', 'LAMP', 2),
(10149, 'A-02-09', 'FAN', 2),
(10150, 'A-02-09', 'CHAIR', 2),
(10151, 'A-02-10', 'DESK', 2),
(10152, 'A-02-10', 'LOCKER', 2),
(10153, 'A-02-10', 'LAMP', 2),
(10154, 'A-02-10', 'FAN', 2),
(10155, 'A-02-10', 'CHAIR', 2),
(10156, 'B-02-01', 'DESK', 2),
(10157, 'B-02-01', '	LOCKER', 2),
(10158, 'B-02-01', 'LAMP', 2),
(10159, 'B-02-01', 'FAN', 2),
(10160, 'B-02-01', 'CHAIR', 2),
(10161, 'B-02-02', 'DESK', 2),
(10162, 'B-02-02', '	LOCKER', 2),
(10163, 'B-02-02', 'LAMP', 2),
(10164, 'B-02-02', 'FAN', 2),
(10165, 'B-02-02', 'CHAIR', 2),
(10166, 'B-02-03', 'DESK', 2),
(10167, 'B-02-03', '	LOCKER', 2),
(10168, 'B-02-03', 'LAMP', 2),
(10169, 'B-02-03', 'FAN', 2),
(10170, 'B-02-03', 'CHAIR', 2),
(10171, 'B-02-04', 'DESK', 2),
(10172, 'B-02-04', 'LOCKER', 2),
(10173, 'B-02-04', 'LAMP', 2),
(10174, 'B-02-04', 'FAN', 2),
(10175, 'B-02-04', 'CHAIR', 2),
(10176, 'B-02-05', 'DESK', 2),
(10177, 'B-02-05', 'LOCKER', 2),
(10178, 'B-02-05', 'LAMP', 2),
(10179, 'B-02-05', 'FAN', 2),
(10180, 'B-02-05', 'CHAIR', 2),
(10181, 'B-02-06', 'DESK', 2),
(10182, 'B-02-06', 'LOCKER', 2),
(10183, 'B-02-06', 'LAMP', 2),
(10184, 'B-02-06', 'FAN', 2),
(10185, 'B-02-06', 'CHAIR', 2),
(10186, 'B-02-07', 'DESK', 2),
(10187, 'B-02-07', 'LOCKER', 2),
(10188, 'B-02-07', 'LAMP', 2),
(10189, 'B-02-07', 'FAN', 2),
(10190, 'B-02-07', 'CHAIR', 2),
(10191, 'B-02-08', 'DESK', 2),
(10192, 'B-02-08', 'LOCKER', 2),
(10193, 'B-02-08', 'LAMP', 2),
(10194, 'B-02-08', 'FAN', 2),
(10195, 'B-02-08', 'CHAIR', 2),
(10196, 'B-02-09', 'DESK', 2),
(10197, 'B-02-09', 'LOCKER', 2),
(10198, 'B-02-09', 'LAMP', 2),
(10199, 'B-02-09', 'FAN', 2),
(10200, 'B-02-09', 'CHAIR', 2),
(10201, 'B-02-10', 'DESK', 2),
(10202, 'B-02-10', 'LOCKER', 2),
(10203, 'B-02-10', 'LAMP', 2),
(10204, 'B-02-10', 'FAN', 2),
(10205, 'B-02-10', 'CHAIR', 2),
(10206, 'B-01-03', 'DESK', 2),
(10207, 'B-01-03', '	LOCKER', 2),
(10208, 'B-01-03', 'LAMP', 2),
(10209, 'B-01-03', 'FAN', 2),
(10210, 'B-01-03', 'CHAIR', 2),
(10211, 'B-01-04', 'DESK', 2),
(10212, 'B-01-04', 'LOCKER', 2),
(10213, 'B-01-04', 'LAMP', 2),
(10214, 'B-01-04', 'FAN', 2),
(10215, 'B-01-04', 'CHAIR', 2),
(10216, 'B-01-05', 'DESK', 2),
(10217, 'B-01-05', 'LOCKER', 2),
(10218, 'B-01-05', 'LAMP', 2),
(10219, 'B-01-05', 'FAN', 2),
(10220, 'B-01-05', 'CHAIR', 2),
(10221, 'B-01-06', 'DESK', 2),
(10222, 'B-01-06', 'LOCKER', 2),
(10223, 'B-01-06', 'LAMP', 2),
(10224, 'B-01-06', 'FAN', 2),
(10225, 'B-01-06', 'CHAIR', 2),
(10226, 'B-01-07', 'DESK', 2),
(10227, 'B-01-07', 'LOCKER', 2),
(10228, 'B-01-07', 'LAMP', 2),
(10229, 'B-01-07', 'FAN', 2),
(10230, 'B-01-07', 'CHAIR', 2),
(10231, 'B-01-08', 'DESK', 2),
(10232, 'B-01-08', 'LOCKER', 2),
(10233, 'B-01-08', 'LAMP', 2),
(10234, 'B-01-08', 'FAN', 2),
(10235, 'B-01-08', 'CHAIR', 2),
(10236, 'B-01-09', 'DESK', 2),
(10237, 'B-01-09', 'LOCKER', 2),
(10238, 'B-01-09', 'LAMP', 2),
(10239, 'B-01-09', 'FAN', 2),
(10240, 'B-01-09', 'CHAIR', 2),
(10241, 'B-01-10', 'DESK', 2),
(10242, 'B-01-10', 'LOCKER', 2),
(10243, 'B-01-10', 'LAMP', 2),
(10244, 'B-01-10', 'FAN', 2),
(10245, 'B-01-10', 'CHAIR', 2),
(10250, 'A-01-02', 'HOES RACK', 1),
(10254, 'A-01-02', 'WHITEBOARD', 1);

-- --------------------------------------------------------

--
-- Table structure for table `student`
--

CREATE TABLE `student` (
  `matricNo` varchar(10) NOT NULL,
  `facultyCode` varchar(10) NOT NULL,
  `studentPassword` varchar(8) NOT NULL DEFAULT '12345678',
  `studentName` varchar(50) NOT NULL,
  `studentEmail` varchar(30) NOT NULL,
  `studentPhoneNo` varchar(11) NOT NULL,
  `semester` varchar(5) NOT NULL,
  `dateRegister` date NOT NULL,
  `roomNo` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `student`
--

INSERT INTO `student` (`matricNo`, `facultyCode`, `studentPassword`, `studentName`, `studentEmail`, `studentPhoneNo`, `semester`, `dateRegister`, `roomNo`) VALUES
('B032110109', 'FPTT', '12345678', 'MUHAMMAD AMMAR HUSAINI BIN JAMALULLAIL', 'b032110109@student.com', '01112334456', '3/1', '2023-01-15', 'B-01-01'),
('B032110191', 'FTMK', 'ALIA2468', 'NUR ALIA BINTI ALI', 'b032110191@student.com', '01121103455', '', '2023-01-20', 'A-01-09'),
('B032110193', 'FTKEE', '12345678', 'AINA NABILAH BINTI HALIM', 'b032110193@student.com', '01112335677', '2/1', '2023-01-18', 'A-01-04'),
('B032110197', 'FTMK', 'TIYA1234', 'NUR HUSNA ATHIRAH BINTI AMRI', 'b032110197@student.com', '01123556788', '2/1', '2023-01-18', 'A-01-08'),
('B032110198', 'FTMK', '12345678', 'NUR ALIA HUMAIRA BINTI ALI', 'b032110198@student.com', '0123456788', '1/1', '2023-01-20', 'A-01-05'),
('B032110255', 'FTMK', '12345678', 'NUR AISYAH BINTI MUHAMAD', 'b032110255@student.com', '0182456784', '2/1', '2023-01-13', 'A-01-02'),
('B032110294', 'FTMK', '12345678', 'AUNI AFEEQAH BINTI SAIMI', 'b032110294@student.com', '0182015404', '2/1', '2023-01-15', 'A-02-10'),
('B032110396', 'FTMK', '12345678', 'IRDINA FARISYA BINTI MOHD FARID', 'b032110396@student.com', '0127449001', '3/1', '2023-01-18', 'A-01-08'),
('B032110586', 'FTKEE', '12345678', 'MUHAMMAD AMIR BIN ROSLAN', 'b032110586@student.com', '01112110399', '2/2', '2023-01-20', 'B-02-03'),
('B032110898', 'FKEKK', '12345678', 'AINA HAZLINA BINTI MALIK', 'b032110898@student.com', '01123345655', '2/1', '2023-01-20', 'A-01-06'),
('B032110986', 'FKP', '12345678', 'MUHD IRFAN BIN MOKHTAR', 'b032110986@student.com', '0173415267', '3/1', '2023-01-15', 'B-01-01'),
('B032111717', 'FKEKK', '12345678', 'NUR ATHEELIA HAIFA BINTI HUSAIN', 'b032111717@student.com', '0173568102', '2/1', '2023-01-18', 'A-02-01'),
('B032114555', 'FKEKK', '12345678', 'FAUZIAH BINTI FADZIL', 'b032114555@student.com', '0145567789', '2/1', '2023-01-18', 'A-01-02'),
('B032116767', 'FTKEE', 'ATIQA123', 'NUR ATIQA BINTI KAMARUZAMAN', 'b032110191@student.com', '0112110395', '2/2', '2023-01-18', 'A-01-04');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`admin_id`);

--
-- Indexes for table `appliance_registration`
--
ALTER TABLE `appliance_registration`
  ADD PRIMARY KEY (`registerId`),
  ADD KEY `matricNo` (`matricNo`);

--
-- Indexes for table `electrical_appliance`
--
ALTER TABLE `electrical_appliance`
  ADD PRIMARY KEY (`applianceCode`);

--
-- Indexes for table `faculty`
--
ALTER TABLE `faculty`
  ADD PRIMARY KEY (`facultyCode`);

--
-- Indexes for table `item_report`
--
ALTER TABLE `item_report`
  ADD PRIMARY KEY (`reportId`),
  ADD KEY `itemId` (`itemId`),
  ADD KEY `admin_id` (`admin_id`),
  ADD KEY `roomNo` (`roomNo`);

--
-- Indexes for table `room`
--
ALTER TABLE `room`
  ADD PRIMARY KEY (`roomNo`);

--
-- Indexes for table `room_item`
--
ALTER TABLE `room_item`
  ADD PRIMARY KEY (`itemId`),
  ADD KEY `roomNo` (`roomNo`);

--
-- Indexes for table `student`
--
ALTER TABLE `student`
  ADD PRIMARY KEY (`matricNo`),
  ADD KEY `roomNo` (`roomNo`),
  ADD KEY `facultyCode` (`facultyCode`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `appliance_registration`
--
ALTER TABLE `appliance_registration`
  MODIFY `registerId` int(7) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1000050;

--
-- AUTO_INCREMENT for table `item_report`
--
ALTER TABLE `item_report`
  MODIFY `reportId` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=100016;

--
-- AUTO_INCREMENT for table `room_item`
--
ALTER TABLE `room_item`
  MODIFY `itemId` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10255;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `appliance_registration`
--
ALTER TABLE `appliance_registration`
  ADD CONSTRAINT `appliance_registration_ibfk_1` FOREIGN KEY (`matricNo`) REFERENCES `student` (`matricNo`);

--
-- Constraints for table `item_report`
--
ALTER TABLE `item_report`
  ADD CONSTRAINT `item_report_ibfk_1` FOREIGN KEY (`itemId`) REFERENCES `room_item` (`itemId`),
  ADD CONSTRAINT `item_report_ibfk_2` FOREIGN KEY (`admin_id`) REFERENCES `admin` (`admin_id`),
  ADD CONSTRAINT `item_report_ibfk_3` FOREIGN KEY (`roomNo`) REFERENCES `room` (`roomNo`);

--
-- Constraints for table `room_item`
--
ALTER TABLE `room_item`
  ADD CONSTRAINT `room_item_ibfk_1` FOREIGN KEY (`roomNo`) REFERENCES `room` (`roomNo`);

--
-- Constraints for table `student`
--
ALTER TABLE `student`
  ADD CONSTRAINT `student_ibfk_1` FOREIGN KEY (`roomNo`) REFERENCES `room` (`roomNo`),
  ADD CONSTRAINT `student_ibfk_2` FOREIGN KEY (`facultyCode`) REFERENCES `faculty` (`facultyCode`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

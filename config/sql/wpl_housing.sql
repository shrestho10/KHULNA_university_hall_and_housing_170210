-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: May 10, 2020 at 06:29 AM
-- Server version: 5.7.26
-- PHP Version: 7.2.18

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `wpl_housing`
--

-- --------------------------------------------------------

--
-- Table structure for table `hallpermission`
--

DROP TABLE IF EXISTS `hallpermission`;
CREATE TABLE IF NOT EXISTS `hallpermission` (
  `id` varchar(255) NOT NULL,
  `userid` varchar(255) NOT NULL,
  `hallid` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hallpermission`
--

INSERT INTO `hallpermission` (`id`, `userid`, `hallid`) VALUES
('{D2763925-45E2-49CC-988F-CC37AFB4FB34}', '020201', '{755934EE-5250-4480-980C-AB5A74770B38}'),
('{191CF596-BA56-4D0A-91F9-D1EDAC6992E9}', '222222', '{89606478-8F3F-4CF4-BF93-73160D3EAAF0}'),
('{9D334E57-3066-4B55-9A3A-12A587558BCD}', '111111', '{755934EE-5250-4480-980C-AB5A74770B38}'),
('{B77DB4EE-6F49-432A-AB73-ABFCD53A8B43}', '020201', '{F7A9D391-0127-4053-8345-ADC5207630BA}'),
('{9E1102DC-37C9-4C75-B7EF-00A4B993BE4F}', '020201', '{89606478-8F3F-4CF4-BF93-73160D3EAAF0}'),
('{8A7B5EA0-7A09-47FA-B84F-D9489B4C61D1}', '020201', '{9BDEAC3B-8F43-481D-A434-C116FC635F7E}'),
('{1400922A-1272-40ED-94C2-283A59BF2A73}', '020201', '{9FCF0283-2EE6-450E-870C-69E4757A8654}');

-- --------------------------------------------------------

--
-- Table structure for table `hms_application`
--

DROP TABLE IF EXISTS `hms_application`;
CREATE TABLE IF NOT EXISTS `hms_application` (
  `id` varchar(50) NOT NULL,
  `template_id` varchar(50) NOT NULL,
  `body` text NOT NULL,
  `user_id` varchar(50) NOT NULL,
  `app_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `hms_application_template`
--

DROP TABLE IF EXISTS `hms_application_template`;
CREATE TABLE IF NOT EXISTS `hms_application_template` (
  `id` varchar(50) NOT NULL,
  `receiver` varchar(50) NOT NULL,
  `subject` varchar(128) NOT NULL,
  `body` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hms_application_template`
--

INSERT INTO `hms_application_template` (`id`, `receiver`, `subject`, `body`) VALUES
('{29B5018D-2C2A-48B7-87C4-306AB15A41A4}', 'Provost', 'Application for seat', 'Dear sir,\r\nIt is to state that I am [*FullName*] and I have applied in Masters Program in your prestigious institution. Luckily, I have got admission here upon merit. But I want to mention that I am from Rajshahi. For my studies I have to come to Khulna and the issue is neither I have any relative here nor I know the entire place. I will be totally new for here.\r\n\r\nSir, I want to request you that Kindly, allot me room in University Hostel. I will pay the charges and you will never find me misbehaving. I am hardworking student and I will prove it. Bit assistance of yours is required. Hoping that you will consider my request. I shall be your beholder.\r\n\r\nYours Sincerely,\r\nName: [*FullName*]\r\nUniversity Id: [*UniversityId*]\r\nKhulna University,Khulna');

-- --------------------------------------------------------

--
-- Table structure for table `hms_apply`
--

DROP TABLE IF EXISTS `hms_apply`;
CREATE TABLE IF NOT EXISTS `hms_apply` (
  `id` varchar(40) NOT NULL,
  `application` varchar(5000) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `hms_apply_seat`
--

DROP TABLE IF EXISTS `hms_apply_seat`;
CREATE TABLE IF NOT EXISTS `hms_apply_seat` (
  `id` varchar(128) NOT NULL,
  `hallname` varchar(128) NOT NULL,
  `userid` int(50) NOT NULL,
  `body` text NOT NULL,
  `status` varchar(255) NOT NULL DEFAULT 'Pending',
  `date` date NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hms_apply_seat`
--

INSERT INTO `hms_apply_seat` (`id`, `hallname`, `userid`, `body`, `status`, `date`) VALUES
('{29B17594-44B5-4451-827D-C86D5CCD9E0E}', '{755934EE-5250-4480-980C-AB5A74770B38}', 170210, 'Date: 06/12/2019  \r\nTo,\r\nProvost\r\nSubject:For Seat In Hall', 'Approved for Interview ', '2019-12-06'),
('{F3671D60-16DB-4DFD-9BF7-259DC38BD1D5}', '{89606478-8F3F-4CF4-BF93-73160D3EAAF0}', 150232, 'Date: 06/12/2019  \r\nTo,\r\nProvost\r\nSubject:For Seat In Hall', 'Approved for Interview ', '2019-12-06');

-- --------------------------------------------------------

--
-- Table structure for table `hms_assign`
--

DROP TABLE IF EXISTS `hms_assign`;
CREATE TABLE IF NOT EXISTS `hms_assign` (
  `user_id` varchar(40) NOT NULL,
  `house_id` varchar(128) NOT NULL,
  `room_id` varchar(128) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hms_assign`
--

INSERT INTO `hms_assign` (`user_id`, `house_id`, `room_id`) VALUES
('alamin@cse.com', '{9FCF0283-2EE6-450E-870C-69E4757A8654}', '{72D3958D-D574-45FD-AA78-703A4A601ECC}'),
('bani@cse.com', '{9BDEAC3B-8F43-481D-A434-C116FC635F7E}', '{A1D17493-E22B-4FDB-B4F2-96409257F303}'),
('imran@imran.com', '{9FCF0283-2EE6-450E-870C-69E4757A8654}', '{2256EE66-B95C-459D-9578-6C066E23AC3F}'),
('pp@cse.com', '{755934EE-5250-4480-980C-AB5A74770B38}', '{7DEC8736-8A79-40BE-9F0C-7C82D6B3019D}'),
('ratul@cse.com', '{9FCF0283-2EE6-450E-870C-69E4757A8654}', '{10366D8E-7EE9-43E6-B656-E7794D5B1A20}'),
('shoron@babui.com', '{755934EE-5250-4480-980C-AB5A74770B38}', '{7DEC8736-8A79-40BE-9F0C-7C82D6B3019D}'),
('shuvo@cse.com', '{9FCF0283-2EE6-450E-870C-69E4757A8654}', '{2256EE66-B95C-459D-9578-6C066E23AC3F}'),
('tk@cse.com', '{755934EE-5250-4480-980C-AB5A74770B38}', '{7DEC8736-8A79-40BE-9F0C-7C82D6B3019D}'),
('vao@cse.com', '{755934EE-5250-4480-980C-AB5A74770B38}', '{77265A8E-6696-4D16-970F-CE9D17995A78}');

-- --------------------------------------------------------

--
-- Table structure for table `hms_assistant_provost`
--

DROP TABLE IF EXISTS `hms_assistant_provost`;
CREATE TABLE IF NOT EXISTS `hms_assistant_provost` (
  `assistant_provost_id` varchar(50) NOT NULL,
  `house_id` varchar(50) NOT NULL,
  `name` varchar(200) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hms_assistant_provost`
--

INSERT INTO `hms_assistant_provost` (`assistant_provost_id`, `house_id`, `name`) VALUES
('{18170099-F3A0-45CC-B82F-B889C521422F}', '{755934EE-5250-4480-980C-AB5A74770B38}', 'Assistant Prof. ZZs'),
('{18709568-8909-4119-AF62-FCB0171577DE}', '{755934EE-5250-4480-980C-AB5A74770B38}', 'Assistant Prof. X'),
('{224D01A1-E9E0-4FA9-9DFF-9232A4558083}', '{755934EE-5250-4480-980C-AB5A74770B38}', 'Assistant Prof.'),
('{40ACF6E1-16E5-49F9-91D2-60B172DCE587}', '{755934EE-5250-4480-980C-AB5A74770B38}', 'Assistant Prof. ZZ'),
('{79C4BA3C-E1E7-4368-B20F-34B917F8632F}', '{755934EE-5250-4480-980C-AB5A74770B38}', 'Assistant Prof. Z');

-- --------------------------------------------------------

--
-- Table structure for table `hms_blacklist`
--

DROP TABLE IF EXISTS `hms_blacklist`;
CREATE TABLE IF NOT EXISTS `hms_blacklist` (
  `id` varchar(128) NOT NULL,
  `userid` int(128) NOT NULL,
  `subject` varchar(128) NOT NULL,
  `body` text NOT NULL,
  `app_date` date NOT NULL,
  `link` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hms_blacklist`
--

INSERT INTO `hms_blacklist` (`id`, `userid`, `subject`, `body`, `app_date`, `link`) VALUES
('{64DF1325-F657-4561-90F0-FF41F5D8028E}', 170210, 'Drug Addiction', '', '2019-12-10', './uploads/blacklist/z9y8mxps5c.png');

-- --------------------------------------------------------

--
-- Table structure for table `hms_complain`
--

DROP TABLE IF EXISTS `hms_complain`;
CREATE TABLE IF NOT EXISTS `hms_complain` (
  `id` varchar(128) NOT NULL,
  `complainagainst` int(128) NOT NULL,
  `complainby` int(128) NOT NULL,
  `subject` varchar(255) NOT NULL,
  `body` text NOT NULL,
  `app_date` date NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hms_complain`
--

INSERT INTO `hms_complain` (`id`, `complainagainst`, `complainby`, `subject`, `body`, `app_date`) VALUES
('{C70E6A78-5FE5-41A0-9D0B-F6A6D5B8BEF7}', 150202, 170210, '', 'Date: 30/10/2019                                         \r\n\r\n i have proff', '2019-10-30');

-- --------------------------------------------------------

--
-- Table structure for table `hms_employee`
--

DROP TABLE IF EXISTS `hms_employee`;
CREATE TABLE IF NOT EXISTS `hms_employee` (
  `employee_id` varchar(50) NOT NULL,
  `house_id` varchar(50) NOT NULL,
  `name` varchar(200) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hms_employee`
--

INSERT INTO `hms_employee` (`employee_id`, `house_id`, `name`) VALUES
('{4A1CDE13-63D5-4134-8516-00BFD66F4C28}', '{755934EE-5250-4480-980C-AB5A74770B38}', 'Jamal'),
('{D584A56F-D525-4B00-839C-42F8EB432CD8}', '{755934EE-5250-4480-980C-AB5A74770B38}', 'Section Officer');

-- --------------------------------------------------------

--
-- Table structure for table `hms_history`
--

DROP TABLE IF EXISTS `hms_history`;
CREATE TABLE IF NOT EXISTS `hms_history` (
  `userid` varchar(128) NOT NULL,
  `roomid` varchar(128) NOT NULL,
  `houseid` varchar(128) NOT NULL,
  `date` date NOT NULL,
  `appdate` date NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hms_history`
--

INSERT INTO `hms_history` (`userid`, `roomid`, `houseid`, `date`, `appdate`) VALUES
('alamin@cse.com', '{755934EE-5250-4480-980C-AB5A74770B38}', '{7D815158-7F3C-4112-8554-B352B73DD5FE}', '2019-01-10', '2018-08-10'),
('alamin@cse.com', '{755934EE-5250-4480-980C-AB5A74770B38}', '{14F89FB2-DCBF-4A39-BD25-EDBD2B00F2C6}', '2019-06-10', '2019-01-10'),
('s@g.com', '{755934EE-5250-4480-980C-AB5A74770B38}', '{7DEC8736-8A79-40BE-9F0C-7C82D6B3019D}', '2019-12-08', '2019-12-08');

-- --------------------------------------------------------

--
-- Table structure for table `hms_housing`
--

DROP TABLE IF EXISTS `hms_housing`;
CREATE TABLE IF NOT EXISTS `hms_housing` (
  `id` varchar(40) NOT NULL,
  `name` varchar(40) NOT NULL,
  `type_id` varchar(128) NOT NULL,
  `no_of_floor` int(11) NOT NULL,
  `no_of_room` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hms_housing`
--

INSERT INTO `hms_housing` (`id`, `name`, `type_id`, `no_of_floor`, `no_of_room`) VALUES
('{755934EE-5250-4480-980C-AB5A74770B38}', 'Khan Jahan Ali Hall', '{A10D8B22-8015-4D50-8D4B-BABF1F72B7D4}', 4, 106),
('{89606478-8F3F-4CF4-BF93-73160D3EAAF0}', 'Bangabandhu Sheikh Mujibur Rahman', '{A10D8B22-8015-4D50-8D4B-BABF1F72B7D4}', 4, 96),
('{9BDEAC3B-8F43-481D-A434-C116FC635F7E}', 'Banga Mata Fozilatunnessa Mujib', '{0BCFBE69-B3D3-40CF-B4C0-29228A62631B}', 4, 76),
('{9FCF0283-2EE6-450E-870C-69E4757A8654}', 'Khan Bahadur Ahsanullah', '{A10D8B22-8015-4D50-8D4B-BABF1F72B7D4}', 4, 96),
('{F7A9D391-0127-4053-8345-ADC5207630BA}', 'Aporajita', '{0BCFBE69-B3D3-40CF-B4C0-29228A62631B}', 4, 160);

-- --------------------------------------------------------

--
-- Table structure for table `hms_interview`
--

DROP TABLE IF EXISTS `hms_interview`;
CREATE TABLE IF NOT EXISTS `hms_interview` (
  `id` varchar(128) NOT NULL,
  `userid` varchar(128) NOT NULL,
  `date` date NOT NULL,
  `time` time NOT NULL,
  `hallname` varchar(255) NOT NULL,
  `status` varchar(128) NOT NULL DEFAULT 'Pending',
  `seat` varchar(255) NOT NULL DEFAULT 'NA',
  PRIMARY KEY (`id`),
  UNIQUE KEY `userid` (`userid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hms_interview`
--

INSERT INTO `hms_interview` (`id`, `userid`, `date`, `time`, `hallname`, `status`, `seat`) VALUES
('{2C3818B1-4F71-4B3B-B9D9-37F16916C1C5}', '150232', '2019-12-14', '12:00:00', '{89606478-8F3F-4CF4-BF93-73160D3EAAF0}', 'Done', '202'),
('{4D311C74-EB36-4A9A-95FD-277513D841FC}', '170210', '2019-12-12', '10:00:00', '{755934EE-5250-4480-980C-AB5A74770B38}', 'Pending', 'NA');

-- --------------------------------------------------------

--
-- Table structure for table `hms_issue`
--

DROP TABLE IF EXISTS `hms_issue`;
CREATE TABLE IF NOT EXISTS `hms_issue` (
  `id` varchar(128) NOT NULL,
  `subject` varchar(128) NOT NULL,
  `body` text NOT NULL,
  `app_date` date NOT NULL,
  `link` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hms_issue`
--

INSERT INTO `hms_issue` (`id`, `subject`, `body`, `app_date`, `link`) VALUES
('{9D7B21B9-008D-4855-946E-512E958DF97A}', 'Dirty Washrooms', '', '2019-12-10', './uploads/issues/t5she78rpo.jpg');

-- --------------------------------------------------------

--
-- Table structure for table `hms_notice`
--

DROP TABLE IF EXISTS `hms_notice`;
CREATE TABLE IF NOT EXISTS `hms_notice` (
  `id` varchar(50) NOT NULL,
  `subject` varchar(128) NOT NULL,
  `body` text NOT NULL,
  `app_date` date NOT NULL,
  `link` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=38 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hms_notice`
--

INSERT INTO `hms_notice` (`id`, `subject`, `body`, `app_date`, `link`) VALUES
('{F54CCFC1-DAF7-4619-BC80-B58272EC4202}', 'Hall Feast111', '                                         \r\n\r\n\r\n\r\n\r\n', '2019-12-10', './uploads/notice/1mph68phzc.pdf');

-- --------------------------------------------------------

--
-- Table structure for table `hms_notice_template`
--

DROP TABLE IF EXISTS `hms_notice_template`;
CREATE TABLE IF NOT EXISTS `hms_notice_template` (
  `subject` varchar(128) NOT NULL,
  `body` text NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `hms_provost`
--

DROP TABLE IF EXISTS `hms_provost`;
CREATE TABLE IF NOT EXISTS `hms_provost` (
  `provost_id` varchar(50) NOT NULL,
  `house_id` varchar(50) NOT NULL,
  `provost_name` varchar(200) NOT NULL,
  `UniversityID` varchar(128) NOT NULL,
  PRIMARY KEY (`UniversityID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hms_provost`
--

INSERT INTO `hms_provost` (`provost_id`, `house_id`, `provost_name`, `UniversityID`) VALUES
('{203E9E2C-C8C2-4394-B59F-C8BBEE8FE3CE}', '{755934EE-5250-4480-980C-AB5A74770B38}', 'abc', '111111'),
('{2FF6F409-3B3A-4801-A2A3-C51CBE2FCB6A}', '{89606478-8F3F-4CF4-BF93-73160D3EAAF0}', 'def', '222222');

-- --------------------------------------------------------

--
-- Table structure for table `hms_room`
--

DROP TABLE IF EXISTS `hms_room`;
CREATE TABLE IF NOT EXISTS `hms_room` (
  `room_id` varchar(128) NOT NULL,
  `room_no` int(11) NOT NULL,
  `house_id` varchar(128) NOT NULL,
  `no_of_seat` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hms_room`
--

INSERT INTO `hms_room` (`room_id`, `room_no`, `house_id`, `no_of_seat`) VALUES
('{10366D8E-7EE9-43E6-B656-E7794D5B1A20}', 421, '{9FCF0283-2EE6-450E-870C-69E4757A8654}', 4),
('{14F89FB2-DCBF-4A39-BD25-EDBD2B00F2C6}', 104, '{755934EE-5250-4480-980C-AB5A74770B38}', 4),
('{1B338CD2-4078-44EB-8FE9-7802B602BF22}', 310, '{9FCF0283-2EE6-450E-870C-69E4757A8654}', 4),
('{1EAC74BC-69CA-4602-9720-CD99FC3606CD}', 402, '{755934EE-5250-4480-980C-AB5A74770B38}', 4),
('{2256EE66-B95C-459D-9578-6C066E23AC3F}', 104, '{9FCF0283-2EE6-450E-870C-69E4757A8654}', 4),
('{2C8DCADC-57BC-40FB-B00B-3C0F419D21B9}', 316, '{9FCF0283-2EE6-450E-870C-69E4757A8654}', 4),
('{54D9C880-844D-4069-99E0-9BE86C759217}', 105, '{755934EE-5250-4480-980C-AB5A74770B38}', 4),
('{6E2DC14D-F277-4CD2-B380-1C703349AC67}', 102, '{F7A9D391-0127-4053-8345-ADC5207630BA}', 4),
('{72D3958D-D574-45FD-AA78-703A4A601ECC}', 402, '{9FCF0283-2EE6-450E-870C-69E4757A8654}', 4),
('{77265A8E-6696-4D16-970F-CE9D17995A78}', 124, '{755934EE-5250-4480-980C-AB5A74770B38}', 4),
('{7BA14B98-DDE6-4977-AD32-4E2A0D0D042C}', 101, '{F7A9D391-0127-4053-8345-ADC5207630BA}', 4),
('{7D815158-7F3C-4112-8554-B352B73DD5FE}', 102, '{755934EE-5250-4480-980C-AB5A74770B38}', 4),
('{7DEC8736-8A79-40BE-9F0C-7C82D6B3019D}', 101, '{755934EE-5250-4480-980C-AB5A74770B38}', 4),
('{834E9708-9B75-4085-9760-18F34D01933C}', 102, '{9FCF0283-2EE6-450E-870C-69E4757A8654}', 4),
('{97F41494-7A82-43E1-BA2F-166FE79FE7D2}', 101, '{89606478-8F3F-4CF4-BF93-73160D3EAAF0}', 4),
('{9C763426-8AD7-4354-B380-024FDF0808F7}', 425, '{755934EE-5250-4480-980C-AB5A74770B38}', 4),
('{A1D17493-E22B-4FDB-B4F2-96409257F303}', 408, '{9BDEAC3B-8F43-481D-A434-C116FC635F7E}', 4),
('{BBB00B6C-99DB-44CB-A5BF-B2A204E5AB42}', 202, '{89606478-8F3F-4CF4-BF93-73160D3EAAF0}', 4),
('{BED387CE-9E20-40B2-BF23-39450BD100A8}', 101, '{9FCF0283-2EE6-450E-870C-69E4757A8654}', 4),
('{C71D520E-00C8-40C1-BC0C-53CC0C8EEB85}', 101, '{9BDEAC3B-8F43-481D-A434-C116FC635F7E}', 4),
('{D40D18AE-1D56-4FB5-9A41-CCAA7D7D57DA}', 115, '{755934EE-5250-4480-980C-AB5A74770B38}', 2),
('{DD038795-E84F-437D-A66D-BD568E692DE7}', 425, '{9FCF0283-2EE6-450E-870C-69E4757A8654}', 4),
('{DFAA88EC-204E-402C-B6CB-A83C7AB7A523}', 103, '{755934EE-5250-4480-980C-AB5A74770B38}', 4),
('{E580DC64-8178-499B-BA5E-73EBD9EAFE55}', 201, '{89606478-8F3F-4CF4-BF93-73160D3EAAF0}', 4);

-- --------------------------------------------------------

--
-- Table structure for table `hms_type`
--

DROP TABLE IF EXISTS `hms_type`;
CREATE TABLE IF NOT EXISTS `hms_type` (
  `id` varchar(128) NOT NULL,
  `name` varchar(128) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hms_type`
--

INSERT INTO `hms_type` (`id`, `name`) VALUES
('{A10D8B22-8015-4D50-8D4B-BABF1F72B7D4}', 'Boys Hall'),
('{452DD60B-A7EB-441D-9457-3A4EB70096C4}', 'Dorm'),
('{0BCFBE69-B3D3-40CF-B4C0-29228A62631B}', 'Girls Hall'),
('{3A4F1094-C5A5-4489-91C3-2E1F987FA0CB}', 'Staff Quarters'),
('{CE01A104-B263-4601-8288-05431F61F0DE}', 'Teachers Quarters');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_discipline`
--

DROP TABLE IF EXISTS `tbl_discipline`;
CREATE TABLE IF NOT EXISTS `tbl_discipline` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(50) NOT NULL,
  `ShortCode` varchar(20) DEFAULT NULL,
  `SchoolID` varchar(40) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_discipline`
--

INSERT INTO `tbl_discipline` (`ID`, `Name`, `ShortCode`, `SchoolID`) VALUES
('{0CF37516-06FE-41CD-93AD-D2D1652509D6}', 'Mathematics', 'MATH', '{39DDC0C2-CFC2-4246-8748-8812B1751A5C}'),
('{560A0FC0-6221-497D-8D41-E584EE4BBEE3}', 'Architecture', 'ARCH', '{39DDC0C2-CFC2-4246-8748-8812B1751A5C}'),
('{63F3C00B-6168-4FBD-AB01-7A1FE413BDDE}', 'Forestry and Wood Technology', 'FWT', '{4D46079B-AFA3-40F1-B8D1-6CC9E9F56812}'),
('{AF41CC9F-3BCD-4952-9D02-17184CC40C79}', 'Urban and Rural Planning', 'URP', '{4D46079B-AFA3-40F1-B8D1-6CC9E9F56812}'),
('{E065BBA7-D0C5-4DFA-9768-81B6F056EB4A}', 'Foresty and Marine Resource Technology', 'FMRT', '{4D46079B-AFA3-40F1-B8D1-6CC9E9F56812}'),
('{E7280448-E379-424E-A11D-357F4334AC8D}', 'Physics', 'PHY', '{39DDC0C2-CFC2-4246-8748-8812B1751A5C}'),
('{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'Computer Science and Engineering', 'CSE', '{39DDC0C2-CFC2-4246-8748-8812B1751A5C}');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_discussion`
--

DROP TABLE IF EXISTS `tbl_discussion`;
CREATE TABLE IF NOT EXISTS `tbl_discussion` (
  `ID` varchar(40) NOT NULL,
  `Title` varchar(150) NOT NULL,
  `CategoryID` varchar(40) NOT NULL,
  `Description` varchar(300) NOT NULL,
  `Tag` varchar(200) NOT NULL,
  `CreationDate` datetime NOT NULL,
  `CreatorID` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_discussion`
--

INSERT INTO `tbl_discussion` (`ID`, `Title`, `CategoryID`, `Description`, `Tag`, `CreationDate`, `CreatorID`) VALUES
('{C9FB74F8-8341-4706-BE40-93BFDC3444D0}', 'what is oop', '{3D212234-2F34-4AB0-83EF-1A772068403B}', 'describe oop', 'oop', '2017-04-29 00:00:00', 'mkazi078@uottawa.ca'),
('{DA408BD0-9C9E-46F6-8CF2-00A631B06A26}', 'what is c#', '{44CAEE8D-A9D7-48C8-A2EA-A7463E00FCD6}', 'this is c#', 'oop', '2017-04-29 00:00:00', 'mkazi078@uottawa.ca');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_discussion_category`
--

DROP TABLE IF EXISTS `tbl_discussion_category`;
CREATE TABLE IF NOT EXISTS `tbl_discussion_category` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_discussion_category`
--

INSERT INTO `tbl_discussion_category` (`ID`, `Name`) VALUES
('{3D212234-2F34-4AB0-83EF-1A772068403B}', 'java'),
('{44CAEE8D-A9D7-48C8-A2EA-A7463E00FCD6}', 'c#'),
('{B2AAFE95-2D69-4633-8EBB-19FD30108C69}', 'php'),
('{DF55D487-2341-48BF-8B2B-3123FFE65B0E}', 'python');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_discussion_comment`
--

DROP TABLE IF EXISTS `tbl_discussion_comment`;
CREATE TABLE IF NOT EXISTS `tbl_discussion_comment` (
  `CommentID` varchar(50) NOT NULL,
  `DiscussionID` varchar(40) NOT NULL,
  `Comment` varchar(300) NOT NULL,
  `CreatorID` varchar(40) NOT NULL,
  `CommentTime` datetime NOT NULL,
  `CommentIDTop` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_discussion_comment`
--

INSERT INTO `tbl_discussion_comment` (`CommentID`, `DiscussionID`, `Comment`, `CreatorID`, `CommentTime`, `CommentIDTop`) VALUES
('{00AADED4-6799-4F2C-BECB-ED50F7B03DDE}', '{C9FB74F8-8341-4706-BE40-93BFDC3444D0}', 'new comment', 'mkazi078@uottawa.ca', '2017-06-26 19:18:08', NULL),
('{05FE9DD2-4A13-4E57-B068-2077A86D4AF9}', '{DA408BD0-9C9E-46F6-8CF2-00A631B06A26}', 'bgfb', 'test@test.com', '2017-10-13 06:28:05', NULL),
('{1634B01B-5F82-43EF-96F8-E6149F488424}', '{C9FB74F8-8341-4706-BE40-93BFDC3444D0}', 'it is PIE', 'mkazi078@uottawa.ca', '0000-00-00 00:00:00', NULL),
('{19918AD2-47E4-4BCA-8933-C4A970BBE22E}', '{C9FB74F8-8341-4706-BE40-93BFDC3444D0}', 'gg', 'test@test.com', '2017-08-18 14:27:56', NULL),
('{550A15FC-06B8-43DF-83EE-097E35920170}', '{C9FB74F8-8341-4706-BE40-93BFDC3444D0}', 'little difficult', 'mohidul@gmail.com', '0000-00-00 00:00:00', NULL),
('{77825AF6-606A-4DAD-82ED-CCBABD5485D9}', '{DA408BD0-9C9E-46F6-8CF2-00A631B06A26}', 'gfh', 'test@test.com', '2017-10-13 06:28:15', NULL),
('{A15517C2-883F-4E5E-B0AC-9A1DB556741F}', '{C9FB74F8-8341-4706-BE40-93BFDC3444D0}', 'Polymorphism, inheritence, encapsulation', 'mkazi078@uottawa.ca', '0000-00-00 00:00:00', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `tbl_permission`
--

DROP TABLE IF EXISTS `tbl_permission`;
CREATE TABLE IF NOT EXISTS `tbl_permission` (
  `ID` varchar(100) NOT NULL,
  `Name` varchar(100) NOT NULL,
  `Category` varchar(100) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_permission`
--

INSERT INTO `tbl_permission` (`ID`, `Name`, `Category`) VALUES
('APPLICATION_FORMAT_C', 'APPLICATION_FORMAT_C', 'APPLICATION FORMAT'),
('APPLICATION_FORMAT_D', 'APPLICATION_FORMAT_D', 'APPLICATION FORMAT'),
('APPLICATION_FORMAT_R', 'APPLICATION_FORMAT_R', 'APPLICATION FORMAT'),
('APPLICATION_FORMAT_U', 'APPLICATION_FORMAT_U', 'APPLICATION FORMAT'),
('APPLICATION_TEMPLATE_C', 'APPLICATION_TEMPLATE_C', 'APPLICATION TEMPLATE'),
('APPLICATION_TEMPLATE_D', 'APPLICATION_TEMPLATE_D', 'APPLICATION TEMPLATE'),
('APPLICATION_TEMPLATE_R', 'APPLICATION_TEMPLATE_R', 'APPLICATION TEMPLATE'),
('APPLICATION_TEMPLATE_U', 'APPLICATION_TEMPLATE_U', 'APPLICATION TEMPLATE'),
('APPLY_C', 'APPLY_C', 'APPLY'),
('APPLY_D', 'APPLY_D', 'APPLY'),
('APPLY_FOR_SEAT_C', 'APPLY_FOR_SEAT_C', 'APPLY_FOR_SEAT'),
('APPLY_FOR_SEAT_D', 'APPLY_FOR_SEAT_D', 'APPLY_FOR_SEAT'),
('APPLY_FOR_SEAT_R', 'APPLY_FOR_SEAT_R', 'APPLY_FOR_SEAT'),
('APPLY_FOR_SEAT_U', 'APPLY_FOR_SEAT_U', 'APPLY_FOR_SEAT'),
('APPLY_R', 'APPLY_R', 'APPLY'),
('APPLY_U', 'APPLY_U', 'APPLY'),
('BLACKLIST_C', 'BLACKLIST_C', 'BLACKLIST'),
('BLACKLIST_D', 'BLACKLIST_D', 'BLACKLIST'),
('BLACKLIST_R', 'BLACKLIST_R', 'BLACKLIST'),
('BLACKLIST_U', 'BLACKLIST_U', 'BLACKLIST'),
('COMPLAIN_M_C', 'COMPLAIN_M_C', 'COMPLAIN_M'),
('COMPLAIN_M_D', 'COMPLAIN_M_D', 'COMPLAIN_M'),
('COMPLAIN_M_R', 'COMPLAIN_M_R', 'COMPLAIN_M'),
('COMPLAIN_M_U', 'COMPLAIN_M_U', 'COMPLAIN_M'),
('COMPLAIN_U_C', 'COMPLAIN_U_C', 'COMPLAIN_U'),
('COMPLAIN_U_D', 'COMPLAINE_U_D', 'COMPLAIN_U'),
('COMPLAIN_U_R', 'COMPLAIN_U_R', 'COMPLAIN_U'),
('COMPLAIN_U_U', 'COMPLAIN_U_U', 'COMPLAIN_U'),
('CREATE_COMPLAIN_C', 'CREATE_COMPLAIN_C', 'CREATE_COMPLAIN'),
('CREATE_COMPLAIN_D', 'CREATE_COMPLAIN_D', 'CREATE_COMPLAIN'),
('CREATE_COMPLAIN_R', 'CREATE_COMPLAIN_R', 'CREATE_COMPLAIN'),
('CREATE_COMPLAIN_U', 'CREATE_COMPLAIN_U', 'CREATE_COMPLAIN'),
('CREATE_NOTICE_C', 'CREATE_NOTICE_C', 'CREATE NOTICE'),
('CREATE_NOTICE_D', 'CREATE_NOTICE_D', 'CREATE NOTICE'),
('CREATE_NOTICE_R', 'CREATE_NOTICE_R', 'CREATE NOTICE'),
('CREATE_NOTICE_U', 'CREATE_NOTICE_U', 'CREATE NOTICE'),
('DISCIPLINE_C', 'DISCIPLINE_C', 'DISCIPLINE'),
('DISCIPLINE_D', 'DISCIPLINE_D', 'DISCIPLINE'),
('DISCIPLINE_R', 'DISCIPLINE_R', 'DISCIPLINE'),
('DISCIPLINE_U', 'DISCIPLINE_U', 'DISCIPLINE'),
('DISCUSSION_C', 'DISCUSSION_C', 'DISCUSSION'),
('DISCUSSION_CAT_C', 'DISCUSSION_CAT_C', 'DISCUSSION CATEGORY'),
('DISCUSSION_CAT_D', 'DISCUSSION_CAT_D', 'DISCUSSION CATEGORY'),
('DISCUSSION_CAT_R', 'DISCUSSION_CAT_R', 'DISCUSSION CATEGORY'),
('DISCUSSION_CAT_U', 'DISCUSSION_CAT_U', 'DISCUSSION CATEGORY'),
('DISCUSSION_COMMENT_C', 'DISCUSSION_COMMENT_C', 'DISCUSSION COMMENT'),
('DISCUSSION_COMMENT_D', 'DISCUSSION_COMMENT_D', 'DISCUSSION COMMENT'),
('DISCUSSION_COMMENT_R', 'DISCUSSION_COMMENT_R', 'DISCUSSION COMMENT'),
('DISCUSSION_COMMENT_U', 'DISCUSSION_COMMENT_U', 'DISCUSSION COMMENT'),
('DISCUSSION_D', 'DISCUSSION_D', 'DISCUSSION'),
('DISCUSSION_R', 'DISCUSSION_R', 'DISCUSSION'),
('DISCUSSION_U', 'DISCUSSION_U', 'DISCUSSION'),
('HALL_C', 'HALL_C', 'HALL'),
('HALL_D', 'HALL_D', 'HALL'),
('HALL_R', 'HALL_R', 'HALL'),
('HALL_U', 'HALL_U', 'HALL'),
('HOUSING_APPLICATION_C', 'HOUSING_APPLICATION_C', 'HOUSING APPLICATION'),
('HOUSING_APPLICATION_D', 'HOUSING_APPLICATION_D', 'HOUSING APPLICATION'),
('HOUSING_APPLICATION_MANAGE_C', 'HOUSING_APPLICATION_MANAGE_C', 'HOUSING APPLICATION MANAGE'),
('HOUSING_APPLICATION_MANAGE_D', 'HOUSING_APPLICATION_MANAGE_D', 'HOUSING APPLICATION MANAGE'),
('HOUSING_APPLICATION_MANAGE_R', 'HOUSING_APPLICATION_MANAGE_R', 'HOUSING APPLICATION MANAGE'),
('HOUSING_APPLICATION_MANAGE_U', 'HOUSING_APPLICATION_MANAGE_U', 'HOUSING APPLICATION MANAGE'),
('HOUSING_APPLICATION_R', 'HOUSING_APPLICATION_R', 'HOUSING APPLICATION'),
('HOUSING_APPLICATION_U', 'HOUSING_APPLICATION_U', 'HOUSING APPLICATION'),
('HOUSING_C', 'HOUSING_C', 'HOUSING'),
('HOUSING_D', 'HOUSING_D', 'HOUSING'),
('HOUSING_DETAILS_C', 'HOUSING_DETAILS_C', 'HOUSING DETAILS'),
('HOUSING_DETAILS_D', 'HOUSING_DETAILS_D', 'HOUSING DETAILS'),
('HOUSING_DETAILS_R', 'HOUSING_DETAILS_R', 'HOUSING DETAILS'),
('HOUSING_DETAILS_U', 'HOUSING_DETAILS_U', 'HOUSING DETAILS'),
('HOUSING_M_C', 'HOUSING_M_C', 'HOUSING_M'),
('HOUSING_M_D', 'HOUSING_M_D', 'HOUSING_M'),
('HOUSING_M_R', 'HOUSING_M_R', 'HOUSING_M'),
('HOUSING_M_U', 'HOUSING_M_U', 'HOUSING_M'),
('HOUSING_NEW_C', 'HOUSING_NEW_C', 'HOUSING_NEW'),
('HOUSING_NEW_D', 'HOUSING_NEW_D', 'HOUSING_NEW'),
('HOUSING_NEW_R', 'HOUSING_NEW_R', 'HOUSING_NEW'),
('HOUSING_NEW_U', 'HOUSING_NEW_U', 'HOUSING_NEW'),
('HOUSING_R', 'HOUSING_R', 'HOUSING'),
('HOUSING_ROOM_ASSIGN_C', 'HOUSING_ROOM_ASSIGN_C', 'HOUSING ROOM ASSIGN'),
('HOUSING_ROOM_ASSIGN_D', 'HOUSING_ROOM_ASSIGN_D', 'HOUSING ROOM ASSIGN'),
('HOUSING_ROOM_ASSIGN_R', 'HOUSING_ROOM_ASSIGN_R', 'HOUSING ROOM ASSIGN'),
('HOUSING_ROOM_ASSIGN_U', 'HOUSING_ROOM_ASSIGN_U', 'HOUSING ROOM ASSIGN'),
('HOUSING_ROOM_C', 'HOUSING_ROOM_C', 'HOUSING ROOM'),
('HOUSING_ROOM_D', 'HOUSING_ROOM_D', 'HOUSING ROOM'),
('HOUSING_ROOM_R', 'HOUSING_ROOM_R', 'HOUSING ROOM'),
('HOUSING_ROOM_U', 'HOUSING_ROOM_U', 'HOUSING ROOM'),
('HOUSING_TYPE_C', 'HOUSING_TYPE_C', 'HOUSING TYPE'),
('HOUSING_TYPE_D', 'HOUSING_TYPE_D', 'HOUSING TYPE'),
('HOUSING_TYPE_R', 'HOUSING_TYPE_R', 'HOUSING TYPE'),
('HOUSING_TYPE_U', 'HOUSING_TYPE_U', 'HOUSING TYPE'),
('HOUSING_U', 'HOUSING_U', 'HOUSING'),
('ISSUE_USER_C', 'ISSUE_USER_C', 'ISSUE_USER'),
('ISSUE_USER_D', 'ISSUE_USER_D', 'ISSUE_USER'),
('ISSUE_USER_R', 'ISSUE_USER_R', 'ISSUE_USER'),
('ISSUE_USER_U', 'ISSUE_USER_U', 'ISSUE_USER'),
('ISSUE_U_C', 'ISSUE_U_C', 'ISSUE_U'),
('ISSUE_U_D', 'ISSUE_U_D', 'ISSUE_U'),
('ISSUE_U_R', 'ISSUE_U_R', 'ISSUE_U'),
('ISSUE_U_U', 'ISSUE_U_U', 'ISSUE_U'),
('NOTICE_C', 'NOTICE_C', 'NOTICE'),
('NOTICE_D', 'NOTICE_D', 'NOTICE'),
('NOTICE_M_C', 'NOTICE_M_C', 'NOTICE_M'),
('NOTICE_M_D', 'NOTICE_M_D', 'NOTICE_M'),
('NOTICE_M_R', 'NOTICE_M_R', 'NOTICE_M'),
('NOTICE_M_U', 'NOTICE_M_U', 'NOTICE_M'),
('NOTICE_R', 'NOTICE_R', 'NOTICE'),
('NOTICE_U', 'NOTICE_U', 'NOTICE'),
('NOTICE_U_C', 'NOTICE_U_C', 'NOTICE_U'),
('NOTICE_U_D', 'NOTICE_U_D', 'NOTICE_U'),
('NOTICE_U_R', 'NOTICE_U_R', 'NOTICE_U'),
('NOTICE_U_U', 'NOTICE_U_U', 'NOTICE_U'),
('PERMISSION_C', 'PERMISSION_C', 'PERMISSION'),
('PERMISSION_D', 'PERMISSION_D', 'PERMISSION'),
('PERMISSION_R', 'PERMISSION_R', 'PERMISSION'),
('PERMISSION_U', 'PERMISSION_U', 'PERMISSION'),
('POSITION_C', 'POSITION_C', 'POSITION'),
('POSITION_D', 'POSITION_D', 'POSITION'),
('POSITION_R', 'POSITION_R', 'POSITION'),
('POSITION_U', 'POSITION_U', 'POSITION'),
('ROLE_C', 'ROLE_C', 'ROLE'),
('ROLE_D', 'ROLE_D', 'ROLE'),
('ROLE_R', 'ROLE_R', 'ROLE'),
('ROLE_U', 'ROLE_U', 'ROLE'),
('SCHOOL_C', 'SCHOOL_C', 'SCHOOL'),
('SCHOOL_D', 'SCHOOL_D', 'SCHOOL'),
('SCHOOL_R', 'SCHOOL_R', 'SCHOOL'),
('SCHOOL_U', 'SCHOOL_U', 'SCHOOL'),
('TERM_C', 'TERM_C', 'TERM'),
('TERM_D', 'TERM_D', 'TERM'),
('TERM_R', 'TERM_R', 'TERM'),
('TERM_U', 'TERM_U', 'TERM'),
('USER_C', 'USER_C', 'USER'),
('USER_D', 'USER_D', 'USER'),
('USER_R', 'USER_R', 'USER'),
('USER_U', 'USER_U', 'USER'),
('VIEW_APPLICANTS_C', 'VIEW_APPLICANTS_C', 'VIEW_APPLICANTS'),
('VIEW_APPLICANTS_D', 'VIEW_APPLICANTS_D', 'VIEW_APPLICANTS'),
('VIEW_APPLICANTS_R', 'VIEW_APPLICANTS_R', 'VIEW_APPLICANTS'),
('VIEW_APPLICANTS_U', 'VIEW_APPLICANTS_U', 'VIEW_APPLICANTS'),
('YEAR_C', 'YEAR_C', 'YEAR'),
('YEAR_D', 'YEAR_D', 'YEAR'),
('YEAR_R', 'YEAR_R', 'YEAR'),
('YEAR_U', 'YEAR_U', 'YEAR');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_position`
--

DROP TABLE IF EXISTS `tbl_position`;
CREATE TABLE IF NOT EXISTS `tbl_position` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_position`
--

INSERT INTO `tbl_position` (`ID`, `Name`) VALUES
('{1BFE76DB-C2AA-4FAA-A23B-F43E6150A2F6}', 'Section Officer'),
('{2E024DF5-BD45-4EF2-A5E3-43BCA3E9777F}', 'Pro-vice Chancellor'),
('{64D25DDA-16B6-47B8-BBFC-4E2AAF5680C7}', 'Assistant Professor'),
('{7CDA1F32-A2F8-4469-B5A8-C2038FCE1F9A}', 'Lecturer'),
('{818DE12F-60CC-42E4-BAEC-48EAAED65179}', 'Dean of School'),
('{928EE9FF-E02D-470F-9A6A-AD0EB38B848F}', 'Vice Chancellor'),
('{92FDDA3F-1E91-4AA3-918F-EB595F85790C}', 'Daywise Worker'),
('{932CB0EE-76C2-448E-A40E-2D167EECC479}', 'Registrar'),
('{ADA027D3-21C1-47AF-A21D-759CAFCFE58D}', 'Assistant Registrar'),
('{B76EB035-EA26-4CEB-B029-1C6129574D98}', 'Librarian'),
('{B78C7A7B-4D38-4025-8170-7B8C9F291946}', 'Head of Discipline'),
('{C27B6BCF-FB83-4F3D-85CA-B7870D8B12D0}', 'Associate Professor'),
('{EB4880E2-01B3-4C6E-A2C9-89B6E5427C0A}', 'Professor');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_role`
--

DROP TABLE IF EXISTS `tbl_role`;
CREATE TABLE IF NOT EXISTS `tbl_role` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_role`
--

INSERT INTO `tbl_role` (`ID`, `Name`) VALUES
('administrator', 'Administrator'),
('registration coordinator', 'Registration Coordinator'),
('student', 'Student'),
('stuff', 'Stuff'),
('tabulator', 'Tabulator'),
('teacher', 'Teacher');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_role_permission`
--

DROP TABLE IF EXISTS `tbl_role_permission`;
CREATE TABLE IF NOT EXISTS `tbl_role_permission` (
  `Row` int(11) NOT NULL AUTO_INCREMENT,
  `RoleID` varchar(40) NOT NULL,
  `PermissionID` varchar(100) NOT NULL,
  PRIMARY KEY (`Row`)
) ENGINE=InnoDB AUTO_INCREMENT=13036 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_role_permission`
--

INSERT INTO `tbl_role_permission` (`Row`, `RoleID`, `PermissionID`) VALUES
(2394, '', 'NOTICE_C'),
(2395, '', 'NOTICE_D'),
(2396, '', 'NOTICE_R'),
(2397, '', 'NOTICE_U'),
(2398, '', 'NOTICE_M_C'),
(2399, '', 'NOTICE_M_D'),
(2400, '', 'NOTICE_M_R'),
(2401, '', 'NOTICE_M_U'),
(2402, '', 'NOTICE_U_C'),
(2403, '', 'NOTICE_U_D'),
(2404, '', 'NOTICE_U_R'),
(2405, '', 'NOTICE_U_U'),
(12702, 'student', 'APPLICATION_FORMAT_C'),
(12703, 'student', 'APPLICATION_FORMAT_D'),
(12704, 'student', 'APPLICATION_FORMAT_R'),
(12705, 'student', 'APPLICATION_FORMAT_U'),
(12706, 'student', 'APPLICATION_TEMPLATE_C'),
(12707, 'student', 'APPLICATION_TEMPLATE_D'),
(12708, 'student', 'APPLICATION_TEMPLATE_R'),
(12709, 'student', 'APPLICATION_TEMPLATE_U'),
(12710, 'student', 'APPLY_C'),
(12711, 'student', 'APPLY_D'),
(12712, 'student', 'APPLY_R'),
(12713, 'student', 'APPLY_U'),
(12714, 'student', 'APPLY_FOR_SEAT_C'),
(12715, 'student', 'APPLY_FOR_SEAT_D'),
(12716, 'student', 'APPLY_FOR_SEAT_R'),
(12717, 'student', 'APPLY_FOR_SEAT_U'),
(12718, 'student', 'COMPLAIN_M_C'),
(12719, 'student', 'COMPLAIN_M_D'),
(12720, 'student', 'COMPLAIN_M_R'),
(12721, 'student', 'COMPLAIN_M_U'),
(12722, 'student', 'COMPLAIN_U_C'),
(12723, 'student', 'COMPLAIN_U_D'),
(12724, 'student', 'COMPLAIN_U_R'),
(12725, 'student', 'COMPLAIN_U_U'),
(12726, 'student', 'CREATE_COMPLAIN_C'),
(12727, 'student', 'CREATE_COMPLAIN_D'),
(12728, 'student', 'CREATE_COMPLAIN_R'),
(12729, 'student', 'CREATE_COMPLAIN_U'),
(12730, 'student', 'HOUSING_APPLICATION_C'),
(12731, 'student', 'HOUSING_APPLICATION_D'),
(12732, 'student', 'HOUSING_APPLICATION_R'),
(12733, 'student', 'HOUSING_APPLICATION_U'),
(12734, 'student', 'ISSUE_USER_C'),
(12735, 'student', 'ISSUE_USER_D'),
(12736, 'student', 'ISSUE_USER_R'),
(12737, 'student', 'ISSUE_USER_U'),
(12738, 'student', 'NOTICE_U_D'),
(12739, 'teacher', 'APPLICATION_FORMAT_C'),
(12740, 'teacher', 'APPLICATION_FORMAT_D'),
(12741, 'teacher', 'APPLICATION_FORMAT_R'),
(12742, 'teacher', 'APPLICATION_FORMAT_U'),
(12743, 'teacher', 'APPLICATION_TEMPLATE_C'),
(12744, 'teacher', 'APPLICATION_TEMPLATE_D'),
(12745, 'teacher', 'APPLICATION_TEMPLATE_R'),
(12746, 'teacher', 'APPLICATION_TEMPLATE_U'),
(12747, 'teacher', 'APPLY_C'),
(12748, 'teacher', 'APPLY_D'),
(12749, 'teacher', 'APPLY_R'),
(12750, 'teacher', 'APPLY_U'),
(12751, 'teacher', 'APPLY_FOR_SEAT_C'),
(12752, 'teacher', 'APPLY_FOR_SEAT_D'),
(12753, 'teacher', 'APPLY_FOR_SEAT_R'),
(12754, 'teacher', 'APPLY_FOR_SEAT_U'),
(12755, 'teacher', 'CREATE_NOTICE_C'),
(12756, 'teacher', 'CREATE_NOTICE_D'),
(12757, 'teacher', 'CREATE_NOTICE_R'),
(12758, 'teacher', 'CREATE_NOTICE_U'),
(12759, 'teacher', 'HOUSING_C'),
(12760, 'teacher', 'HOUSING_D'),
(12761, 'teacher', 'HOUSING_R'),
(12762, 'teacher', 'HOUSING_U'),
(12763, 'teacher', 'HOUSING_APPLICATION_C'),
(12764, 'teacher', 'HOUSING_APPLICATION_D'),
(12765, 'teacher', 'HOUSING_APPLICATION_R'),
(12766, 'teacher', 'HOUSING_APPLICATION_U'),
(12767, 'teacher', 'HOUSING_APPLICATION_MANAGE_C'),
(12768, 'teacher', 'HOUSING_APPLICATION_MANAGE_D'),
(12769, 'teacher', 'HOUSING_APPLICATION_MANAGE_R'),
(12770, 'teacher', 'HOUSING_APPLICATION_MANAGE_U'),
(12771, 'teacher', 'HOUSING_DETAILS_C'),
(12772, 'teacher', 'HOUSING_DETAILS_D'),
(12773, 'teacher', 'HOUSING_DETAILS_R'),
(12774, 'teacher', 'HOUSING_DETAILS_U'),
(12775, 'teacher', 'HOUSING_ROOM_C'),
(12776, 'teacher', 'HOUSING_ROOM_D'),
(12777, 'teacher', 'HOUSING_ROOM_R'),
(12778, 'teacher', 'HOUSING_ROOM_U'),
(12779, 'teacher', 'HOUSING_ROOM_ASSIGN_C'),
(12780, 'teacher', 'HOUSING_ROOM_ASSIGN_D'),
(12781, 'teacher', 'HOUSING_ROOM_ASSIGN_R'),
(12782, 'teacher', 'HOUSING_ROOM_ASSIGN_U'),
(12783, 'teacher', 'HOUSING_NEW_C'),
(12784, 'teacher', 'HOUSING_NEW_D'),
(12785, 'teacher', 'HOUSING_NEW_R'),
(12786, 'teacher', 'HOUSING_NEW_U'),
(12787, 'teacher', 'ISSUE_U_C'),
(12788, 'teacher', 'ISSUE_U_D'),
(12789, 'teacher', 'ISSUE_U_R'),
(12790, 'teacher', 'ISSUE_U_U'),
(12791, 'teacher', 'NOTICE_C'),
(12792, 'teacher', 'NOTICE_D'),
(12793, 'teacher', 'NOTICE_R'),
(12794, 'teacher', 'NOTICE_U'),
(12795, 'teacher', 'NOTICE_M_C'),
(12796, 'teacher', 'NOTICE_M_D'),
(12797, 'teacher', 'NOTICE_M_R'),
(12798, 'teacher', 'NOTICE_M_U'),
(12799, 'teacher', 'NOTICE_U_C'),
(12800, 'teacher', 'NOTICE_U_D'),
(12801, 'teacher', 'NOTICE_U_R'),
(12802, 'teacher', 'NOTICE_U_U'),
(12803, 'teacher', 'SCHOOL_C'),
(12804, 'teacher', 'SCHOOL_D'),
(12805, 'teacher', 'SCHOOL_R'),
(12806, 'teacher', 'SCHOOL_U'),
(12807, 'teacher', 'TERM_C'),
(12808, 'teacher', 'TERM_D'),
(12809, 'teacher', 'TERM_R'),
(12810, 'teacher', 'TERM_U'),
(12811, 'teacher', 'USER_D'),
(12812, 'teacher', 'VIEW_APPLICANTS_C'),
(12813, 'teacher', 'VIEW_APPLICANTS_D'),
(12814, 'teacher', 'VIEW_APPLICANTS_R'),
(12815, 'teacher', 'VIEW_APPLICANTS_U'),
(12816, 'teacher', 'YEAR_C'),
(12817, 'teacher', 'YEAR_D'),
(12818, 'teacher', 'YEAR_R'),
(12819, 'teacher', 'YEAR_U'),
(12924, 'administrator', 'APPLICATION_FORMAT_C'),
(12925, 'administrator', 'APPLICATION_FORMAT_D'),
(12926, 'administrator', 'APPLICATION_FORMAT_R'),
(12927, 'administrator', 'APPLICATION_FORMAT_U'),
(12928, 'administrator', 'APPLICATION_TEMPLATE_C'),
(12929, 'administrator', 'APPLICATION_TEMPLATE_D'),
(12930, 'administrator', 'APPLICATION_TEMPLATE_R'),
(12931, 'administrator', 'APPLICATION_TEMPLATE_U'),
(12932, 'administrator', 'APPLY_C'),
(12933, 'administrator', 'APPLY_D'),
(12934, 'administrator', 'APPLY_R'),
(12935, 'administrator', 'APPLY_U'),
(12936, 'administrator', 'APPLY_FOR_SEAT_C'),
(12937, 'administrator', 'APPLY_FOR_SEAT_D'),
(12938, 'administrator', 'APPLY_FOR_SEAT_R'),
(12939, 'administrator', 'APPLY_FOR_SEAT_U'),
(12940, 'administrator', 'BLACKLIST_C'),
(12941, 'administrator', 'BLACKLIST_D'),
(12942, 'administrator', 'BLACKLIST_R'),
(12943, 'administrator', 'BLACKLIST_U'),
(12944, 'administrator', 'CREATE_NOTICE_C'),
(12945, 'administrator', 'CREATE_NOTICE_D'),
(12946, 'administrator', 'CREATE_NOTICE_R'),
(12947, 'administrator', 'CREATE_NOTICE_U'),
(12948, 'administrator', 'DISCIPLINE_C'),
(12949, 'administrator', 'DISCIPLINE_D'),
(12950, 'administrator', 'DISCIPLINE_R'),
(12951, 'administrator', 'DISCIPLINE_U'),
(12952, 'administrator', 'HOUSING_C'),
(12953, 'administrator', 'HOUSING_D'),
(12954, 'administrator', 'HOUSING_R'),
(12955, 'administrator', 'HOUSING_U'),
(12956, 'administrator', 'HOUSING_APPLICATION_C'),
(12957, 'administrator', 'HOUSING_APPLICATION_D'),
(12958, 'administrator', 'HOUSING_APPLICATION_R'),
(12959, 'administrator', 'HOUSING_APPLICATION_U'),
(12960, 'administrator', 'HOUSING_APPLICATION_MANAGE_C'),
(12961, 'administrator', 'HOUSING_APPLICATION_MANAGE_D'),
(12962, 'administrator', 'HOUSING_APPLICATION_MANAGE_R'),
(12963, 'administrator', 'HOUSING_APPLICATION_MANAGE_U'),
(12964, 'administrator', 'HOUSING_DETAILS_C'),
(12965, 'administrator', 'HOUSING_DETAILS_D'),
(12966, 'administrator', 'HOUSING_DETAILS_R'),
(12967, 'administrator', 'HOUSING_DETAILS_U'),
(12968, 'administrator', 'HOUSING_ROOM_C'),
(12969, 'administrator', 'HOUSING_ROOM_D'),
(12970, 'administrator', 'HOUSING_ROOM_R'),
(12971, 'administrator', 'HOUSING_ROOM_U'),
(12972, 'administrator', 'HOUSING_ROOM_ASSIGN_C'),
(12973, 'administrator', 'HOUSING_ROOM_ASSIGN_D'),
(12974, 'administrator', 'HOUSING_ROOM_ASSIGN_R'),
(12975, 'administrator', 'HOUSING_ROOM_ASSIGN_U'),
(12976, 'administrator', 'HOUSING_TYPE_C'),
(12977, 'administrator', 'HOUSING_TYPE_D'),
(12978, 'administrator', 'HOUSING_TYPE_R'),
(12979, 'administrator', 'HOUSING_TYPE_U'),
(12980, 'administrator', 'HOUSING_M_C'),
(12981, 'administrator', 'HOUSING_M_D'),
(12982, 'administrator', 'HOUSING_M_R'),
(12983, 'administrator', 'HOUSING_M_U'),
(12984, 'administrator', 'HOUSING_NEW_C'),
(12985, 'administrator', 'HOUSING_NEW_D'),
(12986, 'administrator', 'HOUSING_NEW_R'),
(12987, 'administrator', 'HOUSING_NEW_U'),
(12988, 'administrator', 'ISSUE_U_C'),
(12989, 'administrator', 'ISSUE_U_D'),
(12990, 'administrator', 'ISSUE_U_R'),
(12991, 'administrator', 'ISSUE_U_U'),
(12992, 'administrator', 'ISSUE_USER_C'),
(12993, 'administrator', 'ISSUE_USER_D'),
(12994, 'administrator', 'ISSUE_USER_R'),
(12995, 'administrator', 'ISSUE_USER_U'),
(12996, 'administrator', 'NOTICE_C'),
(12997, 'administrator', 'NOTICE_D'),
(12998, 'administrator', 'NOTICE_R'),
(12999, 'administrator', 'NOTICE_U'),
(13000, 'administrator', 'NOTICE_M_C'),
(13001, 'administrator', 'NOTICE_M_D'),
(13002, 'administrator', 'NOTICE_M_R'),
(13003, 'administrator', 'NOTICE_M_U'),
(13004, 'administrator', 'NOTICE_U_C'),
(13005, 'administrator', 'NOTICE_U_D'),
(13006, 'administrator', 'NOTICE_U_R'),
(13007, 'administrator', 'NOTICE_U_U'),
(13008, 'administrator', 'PERMISSION_C'),
(13009, 'administrator', 'PERMISSION_D'),
(13010, 'administrator', 'PERMISSION_R'),
(13011, 'administrator', 'PERMISSION_U'),
(13012, 'administrator', 'POSITION_C'),
(13013, 'administrator', 'POSITION_D'),
(13014, 'administrator', 'POSITION_R'),
(13015, 'administrator', 'POSITION_U'),
(13016, 'administrator', 'ROLE_C'),
(13017, 'administrator', 'ROLE_D'),
(13018, 'administrator', 'ROLE_R'),
(13019, 'administrator', 'ROLE_U'),
(13020, 'administrator', 'SCHOOL_C'),
(13021, 'administrator', 'SCHOOL_D'),
(13022, 'administrator', 'SCHOOL_R'),
(13023, 'administrator', 'SCHOOL_U'),
(13024, 'administrator', 'TERM_C'),
(13025, 'administrator', 'TERM_D'),
(13026, 'administrator', 'TERM_R'),
(13027, 'administrator', 'TERM_U'),
(13028, 'administrator', 'USER_C'),
(13029, 'administrator', 'USER_D'),
(13030, 'administrator', 'USER_R'),
(13031, 'administrator', 'USER_U'),
(13032, 'administrator', 'YEAR_C'),
(13033, 'administrator', 'YEAR_D'),
(13034, 'administrator', 'YEAR_R'),
(13035, 'administrator', 'YEAR_U');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_school`
--

DROP TABLE IF EXISTS `tbl_school`;
CREATE TABLE IF NOT EXISTS `tbl_school` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(50) NOT NULL,
  `DeanID` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_school`
--

INSERT INTO `tbl_school` (`ID`, `Name`, `DeanID`) VALUES
('{39DDC0C2-CFC2-4246-8748-8812B1751A5C}', 'Science Engineering and Technology', ''),
('{4D46079B-AFA3-40F1-B8D1-6CC9E9F56812}', 'Life Science', ''),
('{86E0F021-B30D-48D2-B177-247180633C5E}', 'Social Science', ''),
('{879375F7-0A15-4705-AC90-C6786D279EF1}', 'Law and Humanities', ''),
('{CE09AA38-205B-4F50-A0E0-14DB8686C912}', 'Fine Arts', '');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_term`
--

DROP TABLE IF EXISTS `tbl_term`;
CREATE TABLE IF NOT EXISTS `tbl_term` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_term`
--

INSERT INTO `tbl_term` (`ID`, `Name`) VALUES
('{6DE3CF58-3A1A-4D6A-88CF-83F22C27E0BA}', 'Special'),
('{AF8B217E-4E76-41B8-A02A-7115BD4A6BE6}', '2nd'),
('{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', '1st');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_user`
--

DROP TABLE IF EXISTS `tbl_user`;
CREATE TABLE IF NOT EXISTS `tbl_user` (
  `ID` varchar(40) NOT NULL,
  `UniversityID` varchar(20) NOT NULL,
  `Email` varchar(50) NOT NULL,
  `Password` varchar(20) NOT NULL,
  `FirstName` varchar(50) NOT NULL,
  `LastName` varchar(50) NOT NULL,
  `Status` varchar(20) DEFAULT NULL,
  `IsLogged` smallint(1) DEFAULT NULL,
  `IsArchived` smallint(1) DEFAULT NULL,
  `IsDeleted` smallint(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_user`
--

INSERT INTO `tbl_user` (`ID`, `UniversityID`, `Email`, `Password`, `FirstName`, `LastName`, `Status`, `IsLogged`, `IsArchived`, `IsDeleted`) VALUES
('alamin@cse.com', '150212', 'alamin@cse.com', '123', 'Al', 'Amin ', 'approved', NULL, NULL, NULL),
('alice@cse.com', '150224', 'alice@cse.com', '123', 'Rafia', 'Alice', 'approved', NULL, NULL, NULL),
('bani@cse.com', '150230', 'bani@cse.com', '123', 'Suraiya', 'Bani', 'approved', NULL, NULL, NULL),
('dip@cse.com', '140205', 'dip@cse.com', '123', 'Dip', 'Datta', 'pending', NULL, NULL, NULL),
('imran@imran.com', '150203', 'imran@imran.com', '123', 'Imran', 'Hossain', 'approved', NULL, NULL, NULL),
('pp@cse.com', '150215', 'pp@cse.com', '123', 'Pranta', 'Protik', 'approved', NULL, NULL, NULL),
('ratul@cse.com', '150226', 'ratul@cse.com', '123', 'Siamul', 'Ratul', 'approved', NULL, NULL, NULL),
('shoron@babui.com', '150202', 'shoron@babui.com', '123', 'Shaiful', 'Islalm', 'approved', NULL, NULL, NULL),
('shuvo@cse.com', '150233', 'shuvo@cse.com', '123', 'Wahid', 'Shuvo', 'approved', NULL, NULL, NULL),
('test@test.com', '020201', 'test@test.com', '123', 'I AM', 'ADMIN', 'approved', NULL, NULL, NULL),
('tk@cse.com', '150232', 'tk@cse.com', '123', 'Tanmai', 'Ghosh', 'approved', NULL, NULL, NULL),
('vao@cse.com', '150216', 'vao@cse.com', '123', 'Antu', 'Vao', 'approved', NULL, NULL, NULL),
('abc@gmail.com', '111111', 'abc@gmail.com', '123', 'ABC', 'rahman', 'approved', NULL, NULL, NULL),
('s@g.com', '170210', 's@g.com', '123', 's', 'rahman', 'approved', NULL, NULL, NULL),
('def@gmail.com', '222222', 'def@gmail.com', '123', 'def', 'rahman', 'approved', NULL, NULL, NULL);

-- --------------------------------------------------------

--
-- Table structure for table `tbl_user_details`
--

DROP TABLE IF EXISTS `tbl_user_details`;
CREATE TABLE IF NOT EXISTS `tbl_user_details` (
  `ID` varchar(40) NOT NULL,
  `FatherName` varchar(100) DEFAULT NULL,
  `MotherName` varchar(100) DEFAULT NULL,
  `PermanentAddress` varchar(200) DEFAULT NULL,
  `HomePhone` varchar(20) DEFAULT NULL,
  `CurrentAddress` varchar(200) DEFAULT NULL,
  `MobilePhone` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_user_details`
--

INSERT INTO `tbl_user_details` (`ID`, `FatherName`, `MotherName`, `PermanentAddress`, `HomePhone`, `CurrentAddress`, `MobilePhone`) VALUES
('alamin@cse.com', NULL, NULL, NULL, NULL, NULL, NULL),
('alice@cse.com', NULL, NULL, NULL, NULL, NULL, NULL),
('bani@cse.com', NULL, NULL, NULL, NULL, NULL, NULL),
('dip@cse.com', NULL, NULL, NULL, NULL, NULL, NULL),
('imran@imran.com', NULL, NULL, NULL, NULL, NULL, NULL),
('pp@cse.com', NULL, NULL, NULL, NULL, NULL, NULL),
('ratul@cse.com', NULL, NULL, NULL, NULL, NULL, NULL),
('shoron@babui.com', NULL, NULL, NULL, NULL, NULL, NULL),
('shuvo@cse.com', NULL, NULL, NULL, NULL, NULL, NULL),
('test@test.com', 'My father', 'My mother', 'My address', '04100000', 'Same', '0171100000'),
('tk@cse.com', NULL, NULL, NULL, NULL, NULL, NULL),
('vao@cse.com', NULL, NULL, NULL, NULL, NULL, NULL),
('abc@gmail.com', NULL, NULL, NULL, NULL, NULL, NULL),
('s@g.com', NULL, NULL, NULL, NULL, NULL, NULL),
('def@gmail.com', NULL, NULL, NULL, NULL, NULL, NULL);

-- --------------------------------------------------------

--
-- Table structure for table `tbl_user_discipline`
--

DROP TABLE IF EXISTS `tbl_user_discipline`;
CREATE TABLE IF NOT EXISTS `tbl_user_discipline` (
  `UserID` varchar(40) NOT NULL,
  `DisciplineID` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_user_position`
--

DROP TABLE IF EXISTS `tbl_user_position`;
CREATE TABLE IF NOT EXISTS `tbl_user_position` (
  `ID` int(11) NOT NULL,
  `UserID` varchar(40) NOT NULL,
  `PositionID` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_user_role`
--

DROP TABLE IF EXISTS `tbl_user_role`;
CREATE TABLE IF NOT EXISTS `tbl_user_role` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `UserID` varchar(40) NOT NULL,
  `RoleID` varchar(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=115 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_user_role`
--

INSERT INTO `tbl_user_role` (`ID`, `UserID`, `RoleID`) VALUES
(98, 'test@test.com', 'administrator'),
(99, 'test@test.com', 'teacher'),
(100, 'pp@cse.com', 'student'),
(101, 'imran@imran.com', 'student'),
(102, 'bani@cse.com', 'student'),
(103, 'alice@cse.com', 'student'),
(104, 'tk@cse.com', 'student'),
(106, 'vao@cse.com', 'student'),
(107, 'ratul@cse.com', 'student'),
(108, 'shuvo@cse.com', 'student'),
(109, 'alamin@cse.com', 'student'),
(110, 'shoron@babui.com', 'student'),
(111, 'dip@cse.com', 'student'),
(112, 'abc@gmail.com', 'teacher'),
(113, 's@g.com', 'student'),
(114, 'def@gmail.com', 'teacher');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

###
###
#
###
###

Counter usecaseCnt
LabelString          "Use Case: \arabic{usecaseCnt}."
PrettyFormat         "Use Case: ##"
End

Counter subusecaseCnt
Within               usecaseCnt
LabelString          "Sub Use Use Case: \arabic{subusecaseCnt}."
PrettyFormat         "Sub Use Case: ##"
End

Counter subsubusecaseCnt
Within               subusecaseCnt
LabelString          "Sub Sub Use Use Case: \arabic{subsubusecaseCnt}."
PrettyFormat         "Sub Sub Use Case: ##"
End

Counter subsubsubusecaseCnt
Within               subsubusecaseCnt
LabelString          "Sub Sub Sub Use Use Case: \arabic{subsubusecaseCnt}."
PrettyFormat         "Sub Sub Sub Use Case: ##"
End

Style UseCaseList
      Category              UseCase
      KeepEmpty             1
      Margin                Dynamic
      LatexType             Command
      LatexName             listofusecase
      ParIndent             MM
      Align                 Block
      AlignPossible         Block
      LabelType             Static
      LabelString           "--- Use Case List ---"
      LabelFont
        Size                Normal
        Color               Blue
      EndFont
End

AddToPreamble
%%%
% Preamble
%%%
\usepackage{tocloft}
\usepackage{ifthen}
\usepackage{nameref}%
\usepackage{hyperref}%
\usepackage{refstyle}%
\newcommand{\listusecasename}{List of Use Cases}

\newref{usc}{ %
refcmd = {\ref{#1}: \nameref{#1}},
name = {Use~Case~},
names = {Use~Case~},
Name = {Use~Case~},
Names = {Use~Case~},
rngtxt = \RSrngtxt,
lsttxt = \RSlsttxt
}

\newcounter{uscsuccesscnt}
\setcounter{uscsuccesscnt}{0}


%%%
% EndPreamble
%%%
EndPreamble

Style UseCase1
Category              UseCase
RefPrefix usc
LatexType Command
LatexName usecase
LabelType Counter
LabelCounter          usecaseCnt
LabelString           "Use Case \arabic{usecaseCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistof{usecase}{ucs}{\listusecasename}
\makeatletter
\newcommand{\usecase}[1]{%
 \def\@currentlabelname{#1}%
 \setcounter{uscsuccesscnt}{0}
 \refstepcounter{usecase}
 \vspace{5 mm}\par\noindent\textbf{Use Case \theusecase: #1}
 \addcontentsline{ucs}{usecase}{\protect\numberline{\theusecase}#1}\par}

\setcounter{ucsdepth}{1}
\makeatother
EndPreamble
End

Style UseCase2
Category              UseCase
RefPrefix usc
LatexType Command
LatexName subusecase
LabelType Counter

LabelCounter          subusecaseCnt
LabelString           "Use Case \arabic{usecaseCnt}.\arabic{subusecaseCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistentry[usecase]{subusecase}{ucs}{1}
\makeatletter
\newcommand{\subusecase}[1]{%
 \def\@currentlabelname{#1}%
 \setcounter{uscsuccesscnt}{0}
 \refstepcounter{subusecase}
 \vspace{5 mm}\par\noindent\textbf{Use Case \thesubusecase: #1}
 \addcontentsline{ucs}{subusecase}{\protect\numberline{\thesubusecase}#1}}

\setcounter{ucsdepth}{2}
\makeatother
EndPreamble
End


Style UseCase3
Category              UseCase
RefPrefix usc
LatexType Command
LatexName subsubusecase
LabelType Counter

LabelCounter          subsubusecaseCnt
LabelString           "Use Case \arabic{usecaseCnt}.\arabic{subusecaseCnt}.\arabic{subsubusecaseCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistentry[subusecase]{subsubusecase}{ucs}{1}
\makeatletter
\newcommand{\subsubusecase}[1]{%
 \def\@currentlabelname{#1}%
 \setcounter{uscsuccesscnt}{0}
 \refstepcounter{subsubusecase}
 \par\noindent\textbf{Use Case \thesubsubusecase: #1}
 \addcontentsline{ucs}{subsubusecase}{\protect\numberline{\thesubsubusecase}#1}}

\setcounter{ucsdepth}{3}
\makeatother
EndPreamble
End

Style UseCase4
Category              UseCase
RefPrefix usc
LatexType Command
LatexName subsubsubusecase
LabelType Counter

LabelCounter          subsubsubusecaseCnt
LabelString           "Use Case \arabic{usecaseCnt}.\arabic{subusecaseCnt}.\arabic{subsubusecaseCnt}.\arabic{subsubsubusecaseCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistentry[subsubusecase]{subsubsubusecase}{ucs}{1}
\cftsetindents{subsubsubusecase}{1.5em}{3.0em}
\makeatletter
\newcommand{\subsubsubusecase}[1]{%
 \def\@currentlabelname{#1}%
 \setcounter{uscsuccesscnt}{0}
 \refstepcounter{subsubsubusecase}
 \par\noindent\textbf{Use Case \thesubsubsubusecase: #1}
 \addcontentsline{ucs}{subsubsubusecase}{\protect\numberline{\thesubsubsubusecase}#1}}

\setcounter{ucsdepth}{4}
\makeatother
EndPreamble
End

###
###
###

Style PrimaryUser
Category UseCase
LatexType Command
LatexName uscprimaryuser
LabelType Static

LabelString "Primary User: "
OptionalArgs 1
ParSep 0.7
LabelSep x
Margin Dynamic
Preamble
\newcommand{\uscprimaryuser}{%
\par\noindent{Primary User: }
}
EndPreamble
End


###
###
###

Style Goal
Category UseCase
LatexType Command
LatexName uscgoal
LabelType Static

LabelString "Goal: "
OptionalArgs 1
ParSep 0.7
LabelSep x
Margin Dynamic
Preamble
\newcommand{\uscgoal}{%
\par\noindent{Goal: }
}
EndPreamble
End

###
###
#
###
###

Counter uscprereqi
LabelString          "Prerequisite: \arabic{uscprereqi}."
End

Counter uscprereqii
Within               uscprereqi
LabelString          "Prerequisite: (\alph{uscprereqii})"
End

Counter uscprereqiii
Within               uscprereqii
LabelString          "Prerequisite: \roman{uscprereqiii}."
End

Counter uscprereqiv
Within               uscprereqiii
LabelString          "Prerequisite: \Alph{uscprereqiv}."
End

Style Prerequisites
Category              UseCase
Margin                Dynamic
LatexType             Item_Environment
LatexName             uscprerequisites
NextNoIndent          1
LeftMargin            ""
LabelSep              xx
ParSkip               -0.50
ItemSep               -0.2
TopSep                -0.7
BottomSep             0.7
ParSep               .1
Align                 Block
AlignPossible         Block, Left
LabelType             Enumerate
LabelCounter          "uscprereq"
HTMLTag               ol
HTMLItem              li
HTMLLabel             NONE
RefPrefix             enu
Preamble
\usepackage{enumitem}

\newcounter{uscprereqlvl}
\setcounter{uscprereqlvl}{0}

\newcounter{uscprereqcnt}
\setcounter{uscprereqcnt}{0}

\newenvironment{uscprerequisites}
{

\addtocounter{uscprereqlvl}{1}
\par\noindent
\ifnum\theuscprereqlvl=1{Prerequisite Criteria}:\fi
\begin{enumerate}[noitemsep,topsep=0pt,parsep=0pt,partopsep=0pt]
}
{\addtocounter{uscprereqlvl}{-1}\end{enumerate}}
EndPreamble
End



###
###
#
###
###

Counter uscsuccessi
LabelString          "Success: \arabic{uscsuccessi}."
End

Counter uscsuccessii
Within               uscsuccessi
LabelString          "Success: (\alph{uscsuccessii})"
End

Counter uscsuccessiii
Within               uscsuccessii
LabelString          "Success: \roman{uscsuccessiii}."
End

Counter uscsuccessiv
Within               uscsuccessiii
LabelString          "Success: \Alph{uscsuccessiv}."
End

Style SuccessScenario
Category              UseCase
Margin                Dynamic
LatexType             Item_Environment
LatexName             uscsuccessscenario
NextNoIndent          1
LeftMargin            ""
LabelSep              xx
ParSkip               -0.50
ItemSep               -0.2
TopSep                -0.7
BottomSep             0.7
ParSep               .1
Align                 Block
AlignPossible         Block, Left

LabelType             Enumerate
LabelCounter          "uscsuccess"

HTMLTag               ol
HTMLItem              li
HTMLLabel             NONE
RefPrefix             enu
Preamble
\usepackage{enumitem}

\newcounter{uscsuccesslvl}
\setcounter{uscsuccesslvl}{0}

\newenvironment{uscsuccessscenario}
{
\addtocounter{uscsuccesslvl}{1}
\par\noindent
\ifthenelse{\equal{\theuscsuccesslvl}{1}}{%
\ifthenelse{\equal{\theuscsuccesscnt}{0}}{Main Success Scenario}{Alternate Success Scenario {\theuscsuccesscnt}:}
\addtocounter{uscsuccesscnt}{1}
}%
{%
}%

\begin{enumerate}[noitemsep,topsep=0pt,parsep=0pt,partopsep=0pt]
}
{\addtocounter{uscsuccesslvl}{-1}\end{enumerate}}
EndPreamble
End


###
###
#
###
###

Counter uscfaili
LabelString          "Failure: \arabic{uscfaili}."
End

Counter uscfailii
Within               uscfaili
LabelString          "Failure: (\alph{uscfailii})"
End

Counter uscfailiii
Within               uscfailii
LabelString          "Failure: \roman{uscfailiii}."
End

Counter uscfailiv
Within               uscfailiii
LabelString          "Failure: \Alph{uscfailiv}."
End

Style FailureScenario
Category              UseCase
Margin                Dynamic
LatexType             Item_Environment
LatexName             uscfailure
NextNoIndent          1
LeftMargin            ""
LabelSep              xx
ParSkip               -0.50
ItemSep               -0.2
TopSep                -0.7
BottomSep             0.7
ParSep               .1
Align                 Block
AlignPossible         Block, Left
LabelType             Enumerate
LabelCounter          "uscfail"
HTMLTag               ol
HTMLItem              li
HTMLLabel             NONE
RefPrefix             enu
Preamble
\usepackage{enumitem}

\newcounter{uscfaillvl}
\setcounter{uscfaillvl}{0}

\newcounter{uscfailcnt}
\setcounter{uscfailcnt}{0}

\newenvironment{uscfailure}
{

\addtocounter{uscfaillvl}{1}
\par\noindent
\ifnum\theuscfaillvl=1{Failure Scenario}:\fi
\begin{enumerate}[noitemsep,topsep=0pt,parsep=0pt,partopsep=0pt]
}
{\addtocounter{uscfaillvl}{-1}\end{enumerate}}
EndPreamble
End




###
###
###
Style UseCaseBreak
      Category              UseCase
      KeepEmpty             1
      Margin                Dynamic
      LatexType             Command
      LatexName             uscbreak
      ParIndent             MM
      Align                 Block
      AlignPossible         Block
      LabelType             Static
      LabelString           "---"
      LabelFont
        Size                Normal
        Color               Blue
      EndFont
      Preamble
\newcommand{\uscbreak}{%
}
     EndPreamble
End

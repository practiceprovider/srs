###
###
#
###
###

Counter featureCnt
LabelString          "Feature: \arabic{featureCnt}."
PrettyFormat         "Feature: ##"
End

Counter subfeatureCnt
Within               featureCnt
LabelString          "Sub Feature: \arabic{subfeatureCnt}."
PrettyFormat         "Sub Feature: ##"
End

Counter subsubfeatureCnt
Within               subfeatureCnt
LabelString          "Sub Sub Feature: \arabic{subsubfeatureCnt}."
PrettyFormat         "Sub Sub Feature: ##"
End

Counter subsubsubfeatureCnt
Within               subsubfeatureCnt
LabelString          "Sub Sub Sub Feature: \arabic{subsubfeatureCnt}."
PrettyFormat         "Sub Sub Sub Feature: ##"
End

Style FeatureList
      Category              Feature
      KeepEmpty             1
      Margin                Dynamic
      LatexType             Command
      LatexName             listoffeature
      ParIndent             MM
      Align                 Block
      AlignPossible         Block
      LabelType             Static
      LabelString           "--- Feature List ---"
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
\newcommand{\listfeaturename}{List of Features}

\newref{feat}{ %
refcmd = {\ref{#1}: \nameref{#1}},
name = {Feature~},
names = {Feature~},
Name = {Feature~},
Names = {Feature~},
rngtxt = \RSrngtxt,
lsttxt = \RSlsttxt
}

%%%
% EndPreamble
%%%
EndPreamble

Style Feature1
Category              Feature
RefPrefix feat
LatexType Command
LatexName feature
LabelType Counter
LabelCounter          featureCnt
LabelString           "Feature \arabic{featureCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistof{feature}{feat}{\listfeaturename}
\makeatletter
\newcommand{\feature}[1]{%
 \def\@currentlabelname{#1}%
 \refstepcounter{feature}
 \par\noindent\textbf{Feature \thefeature: #1}
 \addcontentsline{feat}{feature}{\protect\numberline{\thefeature}#1}\par}

\setcounter{featdepth}{1}
\makeatother
EndPreamble
End

Style Feature2
Category              Feature
RefPrefix feat
LatexType Command
LatexName subfeature
LabelType Counter

LabelCounter          subfeatureCnt
LabelString           "Feature \arabic{featureCnt}.\arabic{subfeatureCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistentry[feature]{subfeature}{feat}{1}
\makeatletter
\newcommand{\subfeature}[1]{%
 \def\@currentlabelname{#1}%
 \refstepcounter{subfeature}
 \par\noindent\textbf{Feature \thesubfeature: #1}
 \addcontentsline{feat}{subfeature}{\protect\numberline{\thesubfeature}#1}}

\setcounter{featdepth}{2}
\makeatother
EndPreamble
End


Style Feature3
Category              Feature
RefPrefix feat
LatexType Command
LatexName subsubfeature
LabelType Counter

LabelCounter          subsubfeatureCnt
LabelString           "Feature \arabic{featureCnt}.\arabic{subfeatureCnt}.\arabic{subsubfeatureCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistentry[subfeature]{subsubfeature}{feat}{1}
\makeatletter
\newcommand{\subsubfeature}[1]{%
 \def\@currentlabelname{#1}%
 \refstepcounter{subsubfeature}
 \par\noindent\textbf{Feature \thesubsubfeature: #1}
 \addcontentsline{feat}{subsubfeature}{\protect\numberline{\thesubsubfeature}#1}}

\setcounter{featdepth}{3}
\makeatother
EndPreamble
End

Style Feature4
Category              Feature
RefPrefix feat
LatexType Command
LatexName subsubsubfeature
LabelType Counter

LabelCounter          subsubsubfeatureCnt
LabelString           "Feature \arabic{featureCnt}.\arabic{subfeatureCnt}.\arabic{subsubfeatureCnt}.\arabic{subsubsubfeatureCnt}: "
OptionalArgs 1

LabelSep              xxx
ParSep                0.7
Margin                Dynamic
Font
Series		Bold
EndFont
Preamble
\newlistentry[subsubfeature]{subsubsubfeature}{feat}{1}
\cftsetindents{subsubsubfeature}{1.5em}{3.0em}
\makeatletter
\newcommand{\subsubsubfeature}[1]{%
 \def\@currentlabelname{#1}%
 \refstepcounter{subsubsubfeature}
 \par\noindent\textbf{Feature \thesubsubsubfeature: #1}
 \addcontentsline{feat}{subsubsubfeature}{\protect\numberline{\thesubsubsubfeature}#1}}

\setcounter{featdepth}{4}
\makeatother
EndPreamble
End


###
###
#
###
###

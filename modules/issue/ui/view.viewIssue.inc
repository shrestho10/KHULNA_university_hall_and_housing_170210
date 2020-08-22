<?php

include_once MODULES_ISSUE_BLADE.'view.viewIssue.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.housing.inc';

?>



<div class="panel col-md-8 col-md-offset-2" style="border-top: outset; border-left: outset;
                                border-bottom: inset; border-right: inset; margin-top: 50px;">
    <div class="panel-heading" align="center">
        <h4><u>View Issue</u></h4>
    </div>
    <div class="panel-body">
            <table class="table table-bordered">
                <tr>
                    
                    
                    <th>Topic</th>
                    <th>Date</th>
                    <th>Issue</th>
                    <th>Attachment</th>
                </tr>
               
                    <?php


                    $Result = $_ViewIssueBAO->getAllIssue();
                    if ($Result->getIsSuccess()) {
                        $IssueList = $Result->getResultObject();
                        for ($i=0; $i < sizeof($IssueList); $i++) { 
                            $Issue = $IssueList[$i];

                            ?>
                            <tr>
                            
                         <td><?php echo $Issue->getSubject();?></td>
                            <td><?php echo $Issue->getDate();?></td>
                            <td><a href="Issue_show.php?view=<?php echo $Issue->getId();?>" onclick="return ; ">Issue</a></td>

                             <td><a class="btn btn-primary" href="<?php echo "".$Issue->getLinks(); ?>" role="button">Attachment</a>
                         </td>
                            </tr>
                            <?php
                        }
                    }

                    ?>
                
                    
                </table>
            
    </div>
</div>
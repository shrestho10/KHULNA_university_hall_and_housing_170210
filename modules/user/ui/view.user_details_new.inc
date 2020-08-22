<?php

include_once COMMON.'class.common.inc';
include_once 'blade/view.user_details.blade.inc';





?>

<div class="" style="border-top: outset; border-left: outset;
                                border-bottom: inset; border-right: inset; margin-top: 50px;">
    <div class="panel-heading" align="center">
        <h4><u>Details</u></h4>
    </div>
    <div class="panel-body">
            <table class="table table-bordered">
                <tr>
                    
                    <th>ID</th>
                    <th>Email</th>
                   <!-- <th>Subject</th> -->
                    <th>First Name</th>
                    <th>Lastname</th>
                      <th>Address</th>
                    <th>Permanent Address</th>
                   <!-- <th>Subject</th> -->
                    <th>HomePhone</th>
                    <th>Mobile</th>
                    
                </tr>
               
			 
              <tr>	
              	<td><?php echo $userPositions->getUniversityID(); ?> </td>
              	<td><?php echo $userPositions->getID(); ?> </td>
              	<td><?php echo $userPositions->getFirstName(); ?> </td>
              	<td><?php echo $userPositions->getLastName(); ?> </td>
              	 <td><?php echo $userDetails->getPermanentAddress(); ?> </td>
              	<td><?php echo $userDetails->getCurrentAddress(); ?> </td>
              	
              	<td><?php echo $userDetails->getHomePhone(); ?> </td>
              	<td><?php echo $userDetails->getMobilePhone(); ?> </td>

              </tr>




        




                 </table>
     </div>
     </div>
		
			  
	
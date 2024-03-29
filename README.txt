*******************************************************************************
                   DRUPAL MODULE
*******************************************************************************
Name: Google Store Locator
Maintainers: Michael Fuerstnau (michfuer), Dave Pullen (AngryWookie), Michael
             Vanetta (recrit)
Version: 7.x-1.x
*******************************************************************************

OVERVIEW:
This project uses Google's Store Locator Utility Library and Google Maps to
create a 'Store Locator' page that your site visitors can use to find and get
directions to one of your physical stores. It was born out of a need for a
simple to install and easy to use locator feature for Drupal 7. This module is
different from other 'locator' type modules (e.g. OpenLayers Locator) in that
it doesn't require you to have any knowledge of it's dependant modules, and it
allows developers to focus on implementing personal customizations quickly
because the installation process is so light.

*******************************************************************************

HOW IT WORKS:
Google Store Locator creates a data feed View called 'Location Export' that
generates a JSON file of all the location nodes you create. It provides a
content type called 'Store Location' that is composed of addressfield and
geofield fields. Current workflow is to add your locations as nodes of type
'Store Location' and then navigate to [site_name/store_locator] to see the map.
Configuration settings can be changed at:

  admin/Configuration/Google Store Locator

under the 'Search' heading. Note: giving the map and panel displays the full
Content region (no sidebar blocks) produces better visual results.

Some map items you can change by editing the view 'Location Export':

 Map sidebar: Title - GeoJSON Feed Settings, currently set to the node title
 Map sidebar: Description - GeoJSON Feed Settings, currently set to the address
              field but you could create a combined views field that had both
              in a rewrite.
 Map location callout: any remaining views field that is not set to GeoJSON
                       Feed Settings title or description.


ADD STORE FEATURE FILTER LIST:
  The Store Location content type has a field labeled Feature Filter List. This
is the field an admin can edit to add or remove store features (e.g. Open 24hrs,
Sells Product X). Add the potential features a store can have in the 'Allowed
values list' following the required format.
  Edit your store locations and mark the checkboxes next to each feature that
store possesses.
  That's it! The panel portion of the store locator will now have a checkbox
filter for each feature you've added. When your customers use your locator they
will be able to filter the stores displayed based on the features each one has.


*******************************************************************************

INSTALLATION:
1) Use git to clone the 'storelocator' library into sites/all/libraries
(http://code.google.com/p/storelocator/source/checkout)

2) Download and enable the module and all dependencies. Required modules are:
     -views_geojson
     -geofield
     -addressfield
     -geocoder
        -geoPHP
     -strongarm


*******************************************************************************

CREDITS:
1) Google and Chris Broadfoot's 'Store Locator Utility Library' screencast
(http://tinyurl.com/8slmeln)

2) Method for adding locations was borrowed from the OpenLayers Locator module
   with its 'Location' content type.

3) This project was sponsored by Commerce Guys

*******************************************************************************

RESOURCES:
Google Store Locator ref: http://storelocator.googlecode.com/git/index.html

*******************************************************************************

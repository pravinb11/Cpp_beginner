


var READTHEDOCS_DATA = {
    "project": "carla",
    "version": "0.9.12",
    "language": "en",
    "programming_language": "cpp",
    "page": null,
    "theme": "readthedocs",
    "builder": "mkdocs",
    "docroot": "Docs",
    "source_suffix": ".md",
    "api_host": "https://readthedocs.org",
    "ad_free": false,
    "commit": [
        "d23f3dc1340e47265eeea2b1b33b2d3a2d6d4f42"
    ],
    "global_analytics_code": "UA-17997319-1",
    "user_analytics_code": null,
    "features": {
        "docsearch_disabled": true
    }
}

// Old variables
var doc_version = "0.9.12";
var doc_slug = "carla";
var page_name = "None";
var html_theme = "readthedocs";

// mkdocs_page_input_path is only defined on the RTD mkdocs theme but it isn't
// available on all pages (e.g. missing in search result)
if (typeof mkdocs_page_input_path !== "undefined") {
  READTHEDOCS_DATA["page"] = mkdocs_page_input_path.substr(
      0, mkdocs_page_input_path.lastIndexOf(READTHEDOCS_DATA.source_suffix));
}
